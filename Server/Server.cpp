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
void Server::authUser(QString username, QString password)
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
void Server::registrUser(QString username, QString password)
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
    authUser(username, password); //После добавления пользователя - аутентифицируем его

    qDebug() << "Registration " << username << " done";
}

//Отправка списка пользователей клиенту
void Server::getAllUsers()
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

    qDebug() << "Sending users to the user (Id_User = " << current_id << ") is done";
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

    getChats();
}

//Отправка списка чатов клиенту
void Server::getChats()
{
    int current_id = Clients[socket].Id_User; //Id пользователя от которого поступил запрос
    QMap<uint, QString> chatsmap;
    QSqlQuery query;
    query.exec("SELECT * FROM Chats"); //Получаем список всех чатов
    while(query.next())
    {
        int idchat = query.value("Id_chats").toUInt();
        QString chatname = query.value("Chat_Name").toString();
        QString participants = query.value("Ids_Participants").toString();
        QStringList participantsList = participants.split(' ');
        bool current_id_isHere = false;
        foreach (const QString id, participantsList) {
            if(current_id == id.toInt())
            {
                current_id_isHere = true;
                break;
            }
        }
        if(!current_id_isHere) continue; //Если в текущем чате нет Id пользователя от которого поступил запрос - переход к следующему
        //Если чат личный - называем его
        if(chatname == "" && participantsList.size() == 2)
        {

            QString secondusername;
            QSqlQuery privatequery;
            //Если текущий пользователь первый - находим username второго
            if(current_id == participantsList[1].toInt())
            {
                privatequery.prepare("SELECT Username FROM Users WHERE Id_User = :secondParticipantId");
                privatequery.bindValue(":secondParticipantId", participantsList.first());
                privatequery.exec();
                privatequery.next();
                secondusername = query.value(0).toString();
            }
            //Если текущий пользоватлеь второй - находим username первого
            else if(current_id == participantsList.first().toInt())
            {
                privatequery.prepare("SELECT Username FROM Users WHERE Id_User = :secondParticipantId");
                privatequery.bindValue(":secondParticipantId", participantsList[1]);
                privatequery.exec();
                privatequery.next();
                secondusername =  query.value(0).toString();
            }
            chatsmap[idchat] = secondusername;
        }
        else
        {
            chatsmap[idchat] = chatname;
        }
    }
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << SignalType::GetChats << chatsmap;
    socket->write(Data);

    qDebug() << "Sending chats to the user (Id_User = " << current_id << ") is done";

}

//Отправка списка участников чата клиенту
void Server::getChatParticipants(int chatId)
{
    QSqlQuery query;
    //Получаем список Id участников чата из БД
    query.prepare("SELECT Ids_Participants FROM Chats WHERE Id_Chats = :chatId");
    query.bindValue(":chatId", chatId);
    query.exec();
    if(query.next())
    {
        QString participants = query.value(0).toString();
        QStringList participantsIdList = participants.split(' ');
        QStringList participantsList;
        //Получаем username каждого участника
        foreach (const QString id, participantsIdList) {
            query.prepare("SELECT Username FROM Users WHERE Id_User = :id");
            query.bindValue(":id", id.toInt());
            query.exec();
            query.next();
            participantsList << query.value(0).toString();
        }
        //Отправляем на клиент пользователю список всех участников чата
        Data.clear();
        QDataStream out(&Data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << SignalType::GetChatParticipants << participantsList;
        socket->write(Data);

        qDebug() << "Sending chat participants to the user (Id_User = " << Clients[socket].Id_User << ") is done";
    }
}

//Определение и отправка типа чата (по Id) клиенту
void Server::chatType(int chatId)
{
    QSqlQuery query;
    //Получаем чат из БД
    query.prepare("SELECT * FROM Chats WHERE Id_Chats = :chatId");
    query.bindValue(":chatId", chatId);
    query.exec();
    if(query.next())
    {
        QString chatname = query.value("Chat_Name").toString();
        QString participants = query.value("Ids_Participants").toString();
        QStringList participantsIdList = participants.split(' ');
        if(chatname == "" && participantsIdList.size() == 2)
        {
            Data.clear();
            QDataStream out(&Data, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_6_2);
            out << SignalType::IsPrivateChat;
            socket->write(Data);
        }
        else
        {
            Data.clear();
            QDataStream out(&Data, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_6_2);
            out << SignalType::IsGroupChat;
            socket->write(Data);
        }

        qDebug() << "Sending chat type to the user (Id_User = " << Clients[socket].Id_User << ") is done";
    }

}

//Добавление в групповой чат новых пользователей (по Id чата)
void Server::addUsersToChats(QStringList users, int chatId)
{
    QSqlQuery query;
    //Получаем список Id участников чата из БД
    query.prepare("SELECT Ids_Participants FROM Chats WHERE Id_Chats = :chatId");
    query.bindValue(":chatId", chatId);
    query.exec();
    if(query.next())
    {
        QString participants = query.value(0).toString();
        QStringList participantsIdList = participants.split(' ');
        QStringList participantsList;
        //Получаем username каждого участника
        foreach (const QString id, participantsIdList) {
            query.prepare("SELECT Username FROM Users WHERE Id_User = :id");
            query.bindValue(":id", id.toInt());
            query.exec();
            query.next();
            participantsList << query.value(0).toString();
        }
        bool isUpdate = false; //Проверяем, есть ли новые пользователи
        foreach (const QString &user, users) {
            if(participantsList.contains(user)) continue;
            else
            {
                participantsList << user;
                if(!isUpdate) isUpdate = true;
            }
        }
        if(!isUpdate) return;
        QList<int> userIds;
        //Сопоставляем username и Id_User
        foreach (const QString &member, participantsList) {
            query.prepare("SELECT Id_User FROM Users WHERE Username = :member");
            query.bindValue(":member", member);
            query.exec();
            query.next();
            userIds.append(query.value(0).toInt());
        }
        std::sort(userIds.begin(), userIds.end());
        QStringList membersIds;
        foreach (int memberId, userIds) {
            membersIds << QString::number(memberId);
        }
        QString chatmembers = membersIds.join(' '); //Строка для БД участников чата
        //Обновляем ячейку Ids_Participants в БД
        query.prepare("UPDATE Chats SET Ids_Participants = :chatmembers WHERE Id_Chats = :chatId");
        query.bindValue(":chatmembers", chatmembers);
        query.bindValue(":chatId", chatId);
        query.exec();

        qDebug() << "Chat (Id_Chat = " << chatId << ") update participants";
    }

    getChats();
}

//Отправка истории чата пользователю
void Server::getChatStory(int chatId, QTcpSocket *socket)
{
    QSqlQuery query;
    QStringList messages;
    //Получаем все сообщения из базы данных для данного чата
    query.prepare("SELECT * FROM Messages WHERE Id_Chat = :chatId ORDER BY Send_Time");
    query.bindValue(":chatId", chatId);
    query.exec();
    while (query.next()) {
        QString messageText = query.value("Message_Text").toString();
        int senderId = query.value("Id_Sender").toInt();
        QDateTime sendTime = query.value("Send_Time").toDateTime();
        //Получаем имя отправителя
        QSqlQuery userquery;
        userquery.prepare("SELECT Username FROM Users WHERE Id_User = :id");
        userquery.bindValue(":id", senderId);
        userquery.exec();
        if(userquery.next()) {
            QString senderName = userquery.value("Username").toString();
            //Формируем сообщение
            QString message = QString("[%1] %2:  %3")
                                  .arg(sendTime.toString("yyyy-MM-dd hh:mm:ss"))
                                  .arg(senderName)
                                  .arg(messageText);
            messages << message;
        }
    }
    //Отправляем на клиент пользователю историю сообщений чата
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << SignalType::GetChatStory << messages << chatId;
    socket->write(Data);

    qDebug() << "Sending chat story (Id_Chat = "<< chatId <<") to the user (Id_User = " << Clients[socket].Id_User << ") is done";
}

//Добавление в БД нового сообщения и рассылка всем участникам чата обновления
void Server::sendMessage(QString message, QString sender, int chatId)
{
    QSqlQuery query;
    //Получаем Id отправителя
    query.prepare("SELECT Id_User FROM Users WHERE Username = :sender");
    query.bindValue(":sender", sender);
    query.exec();
    if(query.next())
    {
        int senderId = query.value(0).toInt();
        //Добавляем сообщение в БД
        query.prepare("INSERT INTO Messages (Id_Sender, Id_Chat, Message_Text) VALUES (:sender, :chatId, :message)");
        query.bindValue(":sender", senderId);
        query.bindValue(":chatId", chatId);
        query.bindValue(":message", message);
        query.exec();
        //Получаем всех участников чата
        query.prepare("SELECT Ids_Participants FROM Chats WHERE Id_Chats = :chatId");
        query.bindValue(":chatId", chatId);
        query.exec();
        if(query.next())
        {
            QString participants = query.value(0).toString();
            QStringList participantList = participants.split(' ');
            //Рассылка истории сообщений каждому участнику чата
            foreach (QTcpSocket *socket, Clients.keys()) {
                ClientData clientdata = Clients[socket];
                if(participantList.contains(QString::number(clientdata.Id_User))) getChatStory(chatId, socket);
            }
        }
    }
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
            QString message, sender;
            int chatId;
            in >> message;
            in >> sender;
            in >> chatId;
            sendMessage(message, sender,chatId);
            break;
        }
        case SignalType::Authentication:
        {
            QString username, password;
            in >> username;
            in >> password;
            authUser(username, password);
            break;
        }
        case SignalType::Registration:
        {
            QString username, password;
            in >> username;
            in >> password;
            registrUser(username, password);
            break;
        }
        case SignalType::GetAllUsers:
        {
            getAllUsers();
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
        case SignalType::GetChats:
        {
            getChats();
            break;
        }
        case SignalType::GetChatParticipants:
        {
            int chatId;
            in >> chatId;
            getChatParticipants(chatId);
            break;
        }
        case SignalType::ChatType:
        {
            int chatId;
            in >> chatId;
            chatType(chatId);
            break;
        }
        case SignalType::AddUsersToChat:
        {
            QStringList users;
            int chatId;
            in >> users;
            in >> chatId;
            addUsersToChats(users, chatId);
            break;
        }
        case SignalType::GetChatStory:
        {
            int chatId;
            in >> chatId;
            getChatStory(chatId, socket);
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
