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
                       "User_Password TEXT NOT NULL, "
                       "Is_Online BOOL NOT NULL)");
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
    foreach (QTcpSocket* socket, Sockets)
    {
        socket->close();
        socket->deleteLater();
    }
}
void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,&QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected, this, &Server::disablingTheClient);
    Sockets.push_back(socket);
    qDebug() << "Client connected";
}

void Server::SendToClient(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << str;
    for(unsigned short i = 0; i < Sockets.size(); i++)
    {
        Sockets[i]->write(Data);
    }
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok)
    {
        QString str;
        in >> str;
        qDebug() << str;
        SendToClient(str);
    }
    else
    {
        qDebug() << "Error DataStream";
    }
}

void Server::disablingTheClient()
{
    if(socket)
    {
        Sockets.removeOne(socket);
        socket->deleteLater();
        qDebug() << "Client disconnected";
    }
}
