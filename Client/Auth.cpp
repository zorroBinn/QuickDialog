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

//Если сервер сообщил об ошибке аутентификации - вывод информации об ошибке в соответствии с предыдущим действием
void Auth::authError()
{
    if(isRegistration)
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
    if(ui->lineEdit_Password->text() == "")
    {
        ui->lineEdit_Password->setFocus();
    }
    else on_pushButton_Auth_clicked();
}

//Аутентификация пользователя по введённым данным
void Auth::on_pushButton_Auth_clicked()
{
    if(ui->lineEdit_Username->text().trimmed() != "" && ui->lineEdit_Password->text().trimmed() != "")
    {
        ui->lineEdit_Username->text() = "";
        ui->lineEdit_Password->text() = "";
        isRegistration = false;
        //Хэширование пароля
        QString simplepassword = ui->lineEdit_Password->text();
        QString salt = "QuickDialog"; //Соль для хэша
        QByteArray hash = QCryptographicHash::hash((salt + simplepassword).toUtf8(), QCryptographicHash::Sha256);
        QString hashedPassword = hash.toHex();
        emit authUser(ui->lineEdit_Username->text(), hashedPassword);
    }
}

//Регистрация пользователя по введённым данным
void Auth::on_pushButton_Registr_clicked()
{
    if(ui->lineEdit_Username->text().trimmed() != "" && ui->lineEdit_Password->text().trimmed() != "")
    {
        ui->lineEdit_Username->text() = "";
        ui->lineEdit_Password->text() = "";
        isRegistration = true;
        //Хэширование пароля
        QString simplepassword = ui->lineEdit_Password->text();
        QString salt = "QuickDialog"; //Соль для хэша
        QByteArray hash = QCryptographicHash::hash((salt + simplepassword).toUtf8(), QCryptographicHash::Sha256);
        QString hashedPassword = hash.toHex();
        emit registerUser(ui->lineEdit_Username->text(), hashedPassword);
    }
}

