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
    //this->show();
    //Auth *authform = new Auth;
    //authform->show();
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
    out << str;
    socket->write(Data);
    ui->lineEdit_mess->clear();
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok) {
        QString str;
        in >> str;
        ui->textBrowser_current_chat->append(str);
    }
}

void MainWindow::on_pushButton_connect_clicked()
{    socket->connectToHost("192.168.1.103", 2323);
    ui->pushButton_connect->setVisible(false);
}


void MainWindow::on_pushButton_send_clicked()
{
    SendToServer(ui->lineEdit_mess->text());
}


void MainWindow::on_lineEdit_search_returnPressed()
{

}


void MainWindow::on_lineEdit_mess_returnPressed()
{
    if(ui->lineEdit_mess->text() != "") SendToServer(ui->lineEdit_mess->text());
}

