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
    void authUser(QString username, QString password);
    void registrUser(QString username, QString password);
    void getAllUsers();
    void createNewChat(QStringList usernames, QString chatname);
    void getChats();
    void getChatParticipants(int chatId);
    void chatType(int chatId);
    void addUsersToChats(QStringList users, int chatId);
    void getChatStory(int chatId, QTcpSocket *socket);
    void sendMessage(QString message, QString sender, int chatId);

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void disablingTheClient();

};
#endif // SERVER_H
