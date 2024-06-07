#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "Auth.h"
#include "AddUserToChat.h"
#include "NewChat.h"
#include "ClientSignalType.h"
//#include <qDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
    QString Username;
    Auth *authform;
    NewChat *newChat;
    AddUserToChat *addUserToChat;
    QMap<uint, QString> chats;
    uint currentChatId;
    QString currentChatName;
    void SendToServer(QString str);
    void GetAllUsers();
    void GetChats();
    void getChatParticipants(uint chatId);

public slots:
    void slotReadyRead();
    void registerUser(const QString &username, const QString &password);
    void authUser(const QString &username, const QString &password);
    void createNewChat(QStringList users, const QString &chatname);

private slots:
    void on_pushButton_Send_clicked();
    void on_lineEdit_Search_returnPressed();
    void on_lineEdit_Mess_returnPressed();
    void on_pushButton_Chat_NewUser_clicked();
    void on_pushButton_NewChat_clicked();
    void newChatDestroyed();
    void addUserToChatDestroyed();

signals:
    void AuthError(); //Сигнал ошибки аутентификации
    void allUsers(QStringList users); //Сигнал для отправки списка пользователей в окно создания нового чата
    void chatParticipants(QStringList partisipants, QString currentchatname);
};
#endif // MAINWINDOW_H
