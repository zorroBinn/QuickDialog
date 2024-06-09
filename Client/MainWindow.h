#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "Auth.h"
#include "AddUserToChat.h"
#include "NewChat.h"
#include "ClientSignalType.h"
#include <QListWidgetItem>
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
    QMap<int, QString> chats;
    int currentChatId;
    QString currentChatName;
    QString searchKey;
    bool isThisActive = true;
    void sendMessage(QString message, QString sender, int chatId);
    void getAllUsers();
    void getChats();
    void getChatParticipants(int chatId);
    void showUsersInChatList(QStringList users);
    void chatType(int chatId);
    void addUsersToChat(QStringList users, int chatId);
    void getChatStory(int chatId);

public slots:
    void slotReadyRead();
    void registerUser(const QString &username, const QString &password);
    void authUser(const QString &username, const QString &password);
    void createNewChat(QStringList users, const QString &chatname);

private slots:
    void on_pushButton_Send_clicked();
    void on_lineEdit_Mess_returnPressed();
    void on_pushButton_Chat_NewUser_clicked();
    void on_pushButton_NewChat_clicked();
    void newChatDestroyed();
    void addUserToChatDestroyed();
    void on_lineEdit_Search_textEdited(const QString &arg1);
    void on_listWidget_Chats_itemClicked(QListWidgetItem *item);

signals:
    void authError(); //Сигнал ошибки аутентификации
    void allUsersForNewChat(QStringList users); //Сигнал для отправки списка пользователей в окно создания нового чата
    void allUsersForNewParticipants(QStringList users); //Сигнал для отправки списка пользователей в окно добавления пользователей в групповые чаты
    void chatParticipants(QStringList partisipants, QString currentchatname, int chatId); //Сигнал для отпрвки списка участников чата в окно добавления пользователей в групповые чаты
};
#endif // MAINWINDOW_H
