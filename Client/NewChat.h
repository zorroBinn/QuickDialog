#ifndef NEWCHAT_H
#define NEWCHAT_H

#include <QWidget>

namespace Ui {
class NewChat;
}

class NewChat : public QWidget
{
    Q_OBJECT

public:
    explicit NewChat(QWidget *parent = nullptr);
    ~NewChat();

private:
    Ui::NewChat *ui;
};

#endif // NEWCHAT_H
