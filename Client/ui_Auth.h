/********************************************************************************
** Form generated from reading UI file 'Auth.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_H
#define UI_AUTH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Auth
{
public:
    QWidget *widget_down;
    QPushButton *pushButton_auth;
    QPushButton *pushButton_registr;
    QLabel *label_auth;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_username;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_password;

    void setupUi(QWidget *Auth)
    {
        if (Auth->objectName().isEmpty())
            Auth->setObjectName("Auth");
        Auth->resize(600, 450);
        Auth->setMinimumSize(QSize(600, 450));
        Auth->setMaximumSize(QSize(600, 450));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("contact-new")));
        Auth->setWindowIcon(icon);
        Auth->setStyleSheet(QString::fromUtf8(""));
        widget_down = new QWidget(Auth);
        widget_down->setObjectName("widget_down");
        widget_down->setGeometry(QRect(0, 0, 601, 471));
        widget_down->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(68, 0, 104, 255), stop:1 rgba(59, 47, 172, 255));"));
        pushButton_auth = new QPushButton(widget_down);
        pushButton_auth->setObjectName("pushButton_auth");
        pushButton_auth->setGeometry(QRect(100, 320, 131, 41));
        pushButton_auth->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_auth->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(34, 0, 52, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));\n"
"border: none;\n"
"color: rgb(237, 253, 255);\n"
"font: 14pt \"Comic Sans MS\";"));
        pushButton_registr = new QPushButton(widget_down);
        pushButton_registr->setObjectName("pushButton_registr");
        pushButton_registr->setGeometry(QRect(380, 320, 131, 41));
        pushButton_registr->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_registr->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(34, 0, 52, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));\n"
"border: none;\n"
"color: rgb(237, 253, 255);\n"
"font: 14pt \"Comic Sans MS\";"));
        label_auth = new QLabel(widget_down);
        label_auth->setObjectName("label_auth");
        label_auth->setGeometry(QRect(130, 30, 347, 78));
        label_auth->setStyleSheet(QString::fromUtf8("font: italic 42pt \"Comic Sans MS\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(239, 255, 246);"));
        widget = new QWidget(widget_down);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 160, 501, 115));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(widget);
        lineEdit_username->setObjectName("lineEdit_username");
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        lineEdit_username->setFont(font);
        lineEdit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 11, 120);\n"
"color: rgb(255, 255, 255);"));
        lineEdit_username->setMaxLength(50);

        verticalLayout->addWidget(lineEdit_username);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lineEdit_password = new QLineEdit(widget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setFont(font);
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 11, 120);\n"
"color: rgb(255, 255, 255);"));
        lineEdit_password->setMaxLength(50);

        verticalLayout->addWidget(lineEdit_password);


        retranslateUi(Auth);

        QMetaObject::connectSlotsByName(Auth);
    } // setupUi

    void retranslateUi(QWidget *Auth)
    {
        Auth->setWindowTitle(QCoreApplication::translate("Auth", "QuickDialog", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_auth->setToolTip(QCoreApplication::translate("Auth", "<html><head/><body><p>\320\222\321\205\320\276\320\264 \320\262 \320\260\320\272\320\272\320\260\321\203\320\275\321\202</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_auth->setText(QCoreApplication::translate("Auth", "\320\222\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_registr->setToolTip(QCoreApplication::translate("Auth", "<html><head/><body><p>\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\275\320\276\320\262\320\276\320\263\320\276 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_registr->setText(QCoreApplication::translate("Auth", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_auth->setText(QCoreApplication::translate("Auth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("Auth", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("Auth", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Auth: public Ui_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
