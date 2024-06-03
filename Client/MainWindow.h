#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "Auth.h"
#include "AddUserToChat.h"
#include "NewChat.h"
#include "ClientSignalType.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
    QByteArray UnicName;
    void SendToServer(QString str);

public slots:
    void slotReadyRead();
private slots:
    void on_pushButton_connect_clicked();
    void on_pushButton_Send_clicked();
    void on_lineEdit_Search_returnPressed();
    void on_lineEdit_Mess_returnPressed();
    void on_MainWindow_destroyed();
    void on_pushButton_Chat_NewUser_clicked();
    void on_pushButton_NewChat_clicked();
};
#endif // MAINWINDOW_H
