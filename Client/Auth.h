#ifndef AUTH_H
#define AUTH_H

#include <QWidget>

namespace Ui {
class Auth;
}

class Auth : public QWidget
{
    Q_OBJECT

public:
    explicit Auth(QWidget *parent = nullptr);
    ~Auth();

private slots:
    void on_lineEdit_password_returnPressed();

    void on_lineEdit_username_returnPressed();

private:
    Ui::Auth *ui;
};

#endif // AUTH_H
