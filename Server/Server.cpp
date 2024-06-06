#include "Server.h"

//Конструктор сервера
Server::Server()
{
    if(this->listen(QHostAddress::Any, 2024))
    {
        qDebug() << "Server start";
    }
    else
    {
        qDebug() << "Error";
    }

    //Инициализация/открытие базы данных сервера
    ServerDatabase = QSqlDatabase::addDatabase("QSQLITE");
    ServerDatabase.setDatabaseName("QuickDialogDataBase.db");
    if(!ServerDatabase.open())
    {
        qDebug() << "Database opening error";
    }
    QSqlQuery DatabaseQuery; //Запрос к базе данных сервера
    //Создание таблицы клиентов
    DatabaseQuery.exec("CREATE TABLE IF NOT EXISTS Users ("
                       "Id_User INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "Username TEXT NOT NULL UNIQUE, "
                       "User_Password TEXT NOT NULL)");
    //Создание таблицы чатов
    DatabaseQuery.exec("CREATE TABLE IF NOT EXISTS Chats ("
                       "Id_Chats INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "Chat_Name TEXT, "
                       "Ids_Participants TEXT NOT NULL)");
    //Создание таблицы сообщений
    DatabaseQuery.exec("CREATE TABLE IF NOT EXISTS Messages ("
                       "Id_Message INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "Id_Sender INTEGER NOT NULL, "
                       "Id_Chat INTEGER NOT NULL, "
                       "Send_Time DATATIME DEFAULT CURRENT_TIMESTAMP, "
                       "Message_Text TEXT)");
}

//Деструктор сервера
Server::~Server()
{
    //Закрытие всех сокетов при остановке сервера
    foreach (QTcpSocket* socket, Clients.keys())
    {
        socket->close();
        socket->deleteLater();
    }
    //Разрыв коннекта с БД
    QSqlDatabase::database().close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,&QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected, this, &Server::disablingTheClient);
    //Sockets.push_back(socket);
    ClientData clientdata;
    clientdata.Id_User = -1;
    Clients.insert(socket, clientdata);
    qDebug() << "Client connected, socket descriptor: " << socketDescriptor;
}

//Обработка аутентификации пользователя
void Server::AuthUser(QString username, QString password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Username = :username AND User_Password = :password"); //Поиск пользователя с указанным username и password
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();
    if(query.next())
    {
        //Получаем такого пользователя и в мапе сокет-id указываем id
        int Id_User = query.value("Id_User").toInt();
        if (Clients.contains(socket))
        {
            ClientData &clientdata = Clients[socket];
            clientdata.Id_User = Id_User;
        }
        Data.clear();
        QDataStream out(&Data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << SignalType::AuthDone << username;
        socket->write(Data);

        qDebug() << "Auth " << username << " done";
    }
    else
    {
        //Если такого пользователя с таким паролем нет - сообщаем клиенту об ошибке аутентификации
        Data.clear();
        QDataStream out(&Data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << SignalType::AuthError;
        socket->write(Data);

        qDebug() << username << " error auth";
    }
}

//Обработка регистрации пользователя
void Server::RegistrUser(QString username, QString password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Username = :username"); //Проверка на существование пользователя с указанным username
    query.bindValue(":username", username);
    query.exec();
    if(query.next())
    {
        //Если пользователь с таким username уже существует - сообщаем клиенту об ошибке регистрации
        Data.clear();
        QDataStream out(&Data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << SignalType::AuthError;
        socket->write(Data);

        qDebug() << username << " registr error";
        return;
    }
    //Если пользователя с таким username нет - регистрируем
    query.prepare("INSERT INTO Users (Username, User_Password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();
    AuthUser(username, password); //После добавления пользователя - аутентифицируем его
    qDebug() << "Registration " << username << " done";
}

//Отправка списка пользователей клиенту
void Server::GetAllUsers()
{
    QSqlQuery query;
    int current_id = Clients[socket].Id_User; //Id пользователя от которого поступил запрос
    query.prepare("SELECT Username FROM Users WHERE Id_User != :current_id"); //Исключаем из запроса самого клиента, от которого поступил запрос
    query.bindValue(":current_id", current_id);
    query.exec();
    QStringList users;
    while (query.next())
    {
        users << query.value(0).toString();
    }
    //Отправляем на клиент пользователю список всех пользователей (без самого пользователя)
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << SignalType::GetAllUsers << users;
    socket->write(Data);

    qDebug() << "Sending to the user (Id_User = " << current_id << ") is done";
}

//Создание нового чата
void Server::createNewChat(QStringList usernames, QString chatname)
{
    QSqlQuery query;
    QList<int> userIds;
    //Сопоставляем username и Id_User
    foreach (const QString &user, usernames) {
        query.prepare("SELECT Id_User FROM Users WHERE Username = :username");
        query.bindValue(":username", user);
        query.exec();
        query.next();
        userIds.append(query.value(0).toInt());
    }
    userIds.append(Clients[socket].Id_User); //Также добавляем id пользователя, от которого поступил запрос
    std::sort(userIds.begin(), userIds.end());
    QStringList ids;
    foreach (int id, userIds) {
        ids << QString::number(id);
    }
    QString chatmembers = ids.join(' '); //Строка для БД участников чата
    //Проверяем на существование такой чат
    query.prepare("SELECT * FROM Chats WHERE Chat_Name = :chatname AND Ids_Participants = :chatmembers");
    query.bindValue(":chatname", chatname);
    query.bindValue(":chatmembers", chatmembers);
    query.exec();
    if(query.next()) return;
    //Добавляем новый чат в таблицу Chats
    query.prepare("INSERT INTO Chats (Chat_Name, Ids_Participants) VALUES (:chatname, :chatmembers)");
    query.bindValue(":chatname", chatname);
    query.bindValue(":chatmembers", chatmembers);
    query.exec();

    qDebug() << "Chat (Id_Chat = " << query.lastInsertId().toInt() << ") created";
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok)
    {
        SignalType type;
        in >> type;
        switch (type)
        {
        case SignalType::UserMessage:
        {
            QString str;
            in >> str;
            qDebug() << "User " << socketDescriptor() << " sent the message " << str;

            break;
        }
        case SignalType::Authentication:
        {
            QString username, password;
            in >> username;
            in >> password;
            AuthUser(username, password);
            break;
        }
        case SignalType::Registration:
        {
            QString username, password;
            in >> username;
            in >> password;
            RegistrUser(username, password);
            break;
        }
        case SignalType::GetAllUsers:
        {
            GetAllUsers();
            break;
        }
        case SignalType::CreateNewChat:
        {
            QStringList users;
            QString chatname;
            in >> users;
            in >> chatname;
            createNewChat(users, chatname);
            break;
        }
        }

    }
    else
    {
        qDebug() << "Error DataStream";
    }
}

//При отключении клиента удалить его сокет
void Server::disablingTheClient()
{
    if(socket)
    {
        if (Clients[socket].Id_User != -1) qDebug() << "Client (Id_User =" << Clients[socket].Id_User << ") disconnected";
        Clients.remove(socket);
        socket->deleteLater();
    }
}
