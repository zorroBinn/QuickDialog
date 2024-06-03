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
