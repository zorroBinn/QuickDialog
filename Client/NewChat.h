#ifndef NEWCHAT_H
#define NEWCHAT_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class NewChat;
}

class NewChat : public QWidget
{
    Q_OBJECT

public:
    explicit NewChat(QWidget *parent = nullptr);
    ~NewChat();

public slots:
    void GetUsersList(QStringList users);

private slots:
    void on_pushButton_CreateChat_clicked();

    void on_lineEdit_Search_textChanged(const QString &arg1);

    void closeEvent (QCloseEvent *event);


private:
    Ui::NewChat *ui;
    QMap<QString, Qt::CheckState> UserCheckStates; //Хранит пары “имя пользователя - состояние флажка”

signals:
    void CreateNewChat(QStringList users, const QString chatname);
    void thisClosed();
};

#endif // NEWCHAT_H
