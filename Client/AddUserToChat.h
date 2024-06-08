#ifndef ADDUSERTOCHAT_H
#define ADDUSERTOCHAT_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class AddUserToChat;
}

class AddUserToChat : public QWidget
{
    Q_OBJECT

public:
    explicit AddUserToChat(QWidget *parent = nullptr);
    ~AddUserToChat();

public slots:
    void getUsersList(QStringList users);
    void getParticipantsList(QStringList participants, QString chatname, int chatId);

private slots:
    void on_pushButton_AddUsers_clicked();
    void on_lineEdit_Search_textChanged(const QString &arg1);
    void closeEvent (QCloseEvent *event);

private:
    Ui::AddUserToChat *ui;
    QString currentChatName;
    int currentChatId;
    QStringList participants;
    QMap<QString, Qt::CheckState> newChatUsersCheckStates; //Хранит пары “имя пользователя - состояние флажка”

signals:
    void addUser(const QStringList users, int chatId);
    void thisClosed();
};

#endif // ADDUSERTOCHAT_H
