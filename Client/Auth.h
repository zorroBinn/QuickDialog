#ifndef AUTH_H
#define AUTH_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Auth;
}

class Auth : public QWidget
{
    Q_OBJECT

public:
    explicit Auth(QWidget *parent = nullptr);
    ~Auth();

public slots:
    void authError();

private slots:
    void on_lineEdit_Password_returnPressed();
    void on_lineEdit_Username_returnPressed();
    void on_pushButton_Auth_clicked();
    void on_pushButton_Registr_clicked();

private:
    Ui::Auth *ui;
    bool isRegistration;

signals:
    void registerUser(const QString &username, const QString &password); //Сигнал для регистрации
    void authUser(const QString &username, const QString &password); //Сигнал для аутентификации
};

#endif // AUTH_H
