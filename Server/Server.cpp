#include "Server.h"

Server::Server()
{
    if(this->listen(QHostAddress::Any, 2323))
    {
        qDebug() << "Server start";
    }
    else
    {
        qDebug() << "Error";
    }
}
void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,&QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    Sockets.push_back(socket);
    qDebug() << "client connected";
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
