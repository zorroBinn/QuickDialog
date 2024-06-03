#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    Auth *authform = new Auth;
    authform->show();

    this->show();
    //ui->pushButton_chat_newUser->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok) {
        QString str;
        in >> str;
        ui->textBrowser_CurrentChat->append(str);
    }
}

void MainWindow::on_pushButton_connect_clicked()
{
    socket->connectToHost("192.168.1.103", 2024);
}


void MainWindow::on_pushButton_Send_clicked()
{
    SendToServer(ui->lineEdit_Mess->text());
}


void MainWindow::on_lineEdit_Search_returnPressed()
{

}


void MainWindow::on_lineEdit_Mess_returnPressed()
{
    if(ui->lineEdit_Mess->text() != "") SendToServer(ui->lineEdit_Mess->text());
}


void MainWindow::on_MainWindow_destroyed()
{

}


void MainWindow::on_pushButton_Chat_NewUser_clicked()
{
    AddUserToChat* addUser = new AddUserToChat();
    addUser->show();
}


void MainWindow::on_pushButton_NewChat_clicked()
{
    NewChat* newChat = new NewChat();
    newChat->show();
}

