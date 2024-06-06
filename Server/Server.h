#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QTime>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "SignalType.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    ~Server();
    QTcpSocket* socket;

private:
    //QVector <QTcpSocket*> Sockets;
    struct ClientData
    {
        int Id_User;
    };
    QMap<QTcpSocket *, ClientData> Clients;
    QByteArray Data;
    QSqlDatabase ServerDatabase;
    //void SendToClient(QString str);
    void AuthUser(QString username, QString password);
    void RegistrUser(QString username, QString password);
    void GetAllUsers();
    void createNewChat(QStringList usernames, QString chatname);

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void disablingTheClient();

};
#endif // SERVER_H
