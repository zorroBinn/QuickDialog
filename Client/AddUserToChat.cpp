#include "AddUserToChat.h"
#include "ui_AddUserToChat.h"

AddUserToChat::AddUserToChat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddUserToChat)
{
    ui->setupUi(this);
}

AddUserToChat::~AddUserToChat()
{
    delete ui;
}

//Получение списка доступных к приглашению пользователей
void AddUserToChat::getUsersList(QStringList users)
{

}

//Получение списка участников чата
void AddUserToChat::getParticipantsList(QStringList participants, QString chatname)
{

}

void AddUserToChat::on_pushButton_AddUsers_clicked()
{

}


void AddUserToChat::on_lineEdit_Search_textChanged(const QString &arg1)
{

}

void AddUserToChat::closeEvent(QCloseEvent *event)
{
    emit thisClosed();
    event->accept();
}

