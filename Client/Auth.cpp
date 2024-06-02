#include "Auth.h"
#include "ui_Auth.h"

Auth::Auth(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Auth)
{
    ui->setupUi(this);
}

Auth::~Auth()
{
    delete ui;
}

void Auth::on_lineEdit_password_returnPressed()
{

}


void Auth::on_lineEdit_username_returnPressed()
{

}

