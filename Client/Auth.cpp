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

void Auth::on_lineEdit_Password_returnPressed()
{

}


void Auth::on_lineEdit_Username_returnPressed()
{

}

