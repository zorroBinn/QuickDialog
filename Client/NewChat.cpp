#include "NewChat.h"
#include "ui_NewChat.h"

NewChat::NewChat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewChat)
{
    ui->setupUi(this);
}

NewChat::~NewChat()
{
    delete ui;
}
