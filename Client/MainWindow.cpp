#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

//Конструктор основной формы
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    socket->connectToHost("192.168.1.103", 2024);
    authform = new Auth(); //Окно авторизации
    authform->show();
    newchat = new NewChat(); //Окно создания нового чата
    connect(newchat, &NewChat::thisClosed, this, &MainWindow::newChatDestroyed);
    connect(newchat, &NewChat::createNewChat, this, &MainWindow::createNewChat);
    connect(authform, &Auth::registerUser, this, &MainWindow::registerUser);
    connect(authform, &Auth::authUser, this, &MainWindow::authUser);
    //ui->pushButton_Chat_NewUser->setVisible(false);
}

//Деструктор
MainWindow::~MainWindow()
{
    delete ui;
    delete this->newchat;
}

void MainWindow::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::UserMessage << str;
    socket->write(Data);
    ui->lineEdit_Mess->clear();
}

//Запрос на получение списка всех пользователей
void MainWindow::GetAllUsers()
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::GetAllUsers;
    socket->write(Data);
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok) {
        ClientSignalType type;
        in >> type;

        switch(type)
        {
        case ClientSignalType::AuthDone:
        {
            in >> Username;
            authform->close();
            this->show();
            break;
        }
        case ClientSignalType::AuthError:
        {
            connect(this, &MainWindow::AuthError, authform, &Auth::AuthError);
            emit AuthError();
            break;
        }
        case ClientSignalType::GetAllUsers:
        {
            QStringList users;
            in >> users;
            if(!newchat->isHidden())
            {
                connect(this, &MainWindow::AllUsers, newchat, &NewChat::GetUsersList);
                emit AllUsers(users);
            }
            break;
        }
        }
    }
}

//Запрос на регистрацию нового пользователя
void MainWindow::registerUser(const QString &username, const QString &password)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::Registration << username << password;
    socket->write(Data);
}

//Запрос на аутентификацию пользователя
void MainWindow::authUser(const QString &username, const QString &password)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::Authentication << username << password;
    socket->write(Data);
}

//Запрос на создание нового чата
void MainWindow::createNewChat(QStringList users, const QString chatname)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::CreateNewChat << users << chatname;
    socket->write(Data);
}

//При закрытии окна создания нового чата сделать основное окно активным
void MainWindow::newChatDestroyed()
{
    this->setDisabled(false);
    Data.clear();
}


void MainWindow::on_pushButton_Send_clicked()
{
    if(ui->lineEdit_Mess->text().trimmed() != "") SendToServer(ui->lineEdit_Mess->text().trimmed());
}


void MainWindow::on_lineEdit_Search_returnPressed()
{

}


void MainWindow::on_lineEdit_Mess_returnPressed()
{
    if(ui->lineEdit_Mess->text().trimmed() != "") SendToServer(ui->lineEdit_Mess->text());
}


void MainWindow::on_pushButton_Chat_NewUser_clicked()
{
    AddUserToChat* addUser = new AddUserToChat();
    addUser->show();
}


void MainWindow::on_pushButton_NewChat_clicked()
{
    newchat->show();
    this->setDisabled(true);
    GetAllUsers();
}

