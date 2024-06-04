#include "Auth.h"
#include "ui_Auth.h"

Auth::Auth(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Auth)
{
    ui->setupUi(this);
    ui->label_Error->setVisible(false);
}

Auth::~Auth()
{
    delete ui;
}

void Auth::AuthError()
{
    if(IsRegistration)
    {
        ui->label_Error->setText("Пользователь с таким именем уже существует");
        ui->label_Error->setVisible(true);
        ui->lineEdit_Password->setText("");
        ui->lineEdit_Username->setText("");
    }
    else
    {
        ui->label_Error->setText("Неверные учётные данные");
        ui->label_Error->setVisible(true);
        ui->lineEdit_Password->setText("");
        ui->lineEdit_Username->setText("");
    }
}

void Auth::on_lineEdit_Password_returnPressed()
{
    on_pushButton_Auth_clicked();
}


void Auth::on_lineEdit_Username_returnPressed()
{
    on_pushButton_Auth_clicked();
}


void Auth::on_pushButton_Auth_clicked()
{
    if(ui->lineEdit_Username->text().trimmed() != "" && ui->lineEdit_Password->text().trimmed() != "")
    {
        ui->lineEdit_Username->text() = "";
        ui->lineEdit_Password->text() = "";
        IsRegistration = false;
        emit authUser(ui->lineEdit_Username->text(), ui->lineEdit_Password->text());
    }
}


void Auth::on_pushButton_Registr_clicked()
{
    if(ui->lineEdit_Username->text().trimmed() != "" && ui->lineEdit_Password->text().trimmed() != "")
    {
        ui->lineEdit_Username->text() = "";
        ui->lineEdit_Password->text() = "";
        IsRegistration = true;
        emit registerUser(ui->lineEdit_Username->text(), ui->lineEdit_Password->text());
    }
}

