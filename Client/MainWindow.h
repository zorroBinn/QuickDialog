#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "Auth.h"

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
    void on_pushButton_send_clicked();
    void on_lineEdit_search_returnPressed();
    void on_lineEdit_mess_returnPressed();
};
#endif // MAINWINDOW_H
