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
