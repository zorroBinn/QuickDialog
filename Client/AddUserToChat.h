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
    void getParticipantsList(QStringList participants, QString chatname);

private slots:
    void on_pushButton_AddUsers_clicked();
    void on_lineEdit_Search_textChanged(const QString &arg1);
    void closeEvent (QCloseEvent *event);

private:
    Ui::AddUserToChat *ui;
    QString currentChatName;
    QMap<QString, Qt::CheckState> newUserCheckStates; //Хранит пары “имя пользователя - состояние флажка”

signals:
    void addUser(const QStringList users, const QString chatname);
    void thisClosed();
};

#endif // ADDUSERTOCHAT_H
