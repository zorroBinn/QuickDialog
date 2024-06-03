#ifndef ADDUSERTOCHAT_H
#define ADDUSERTOCHAT_H

#include <QWidget>

namespace Ui {
class AddUserToChat;
}

class AddUserToChat : public QWidget
{
    Q_OBJECT

public:
    explicit AddUserToChat(QWidget *parent = nullptr);
    ~AddUserToChat();

private:
    Ui::AddUserToChat *ui;
};

#endif // ADDUSERTOCHAT_H
