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
    QPushButton *pushButton_Auth;
    QPushButton *pushButton_Registr;
    QLabel *label_Auth;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_Username;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_Password;
    QLabel *label_Error;

    void setupUi(QWidget *Auth)
    {
        if (Auth->objectName().isEmpty())
            Auth->setObjectName("Auth");
        Auth->resize(600, 450);
        Auth->setMinimumSize(QSize(600, 450));
        Auth->setMaximumSize(QSize(600, 450));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("contact-new")));
        Auth->setWindowIcon(icon);
        Auth->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(24, 0, 36, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));"));
        widget_down = new QWidget(Auth);
        widget_down->setObjectName("widget_down");
        widget_down->setGeometry(QRect(0, 0, 601, 471));
        widget_down->setStyleSheet(QString::fromUtf8(""));
        pushButton_Auth = new QPushButton(widget_down);
        pushButton_Auth->setObjectName("pushButton_Auth");
        pushButton_Auth->setGeometry(QRect(100, 320, 131, 41));
        pushButton_Auth->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Auth->setFocusPolicy(Qt::NoFocus);
        pushButton_Auth->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(34, 0, 52, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));\n"
"border: 1px solid rgb(0, 0, 127);\n"
"color: rgb(237, 253, 255);\n"
"font: 14pt \"Comic Sans MS\";"));
        pushButton_Registr = new QPushButton(widget_down);
        pushButton_Registr->setObjectName("pushButton_Registr");
        pushButton_Registr->setGeometry(QRect(380, 320, 131, 41));
        pushButton_Registr->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Registr->setFocusPolicy(Qt::NoFocus);
        pushButton_Registr->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(34, 0, 52, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));\n"
"border: 1px solid rgb(0, 0, 127);\n"
"color: rgb(237, 253, 255);\n"
"font: 14pt \"Comic Sans MS\";"));
        label_Auth = new QLabel(widget_down);
        label_Auth->setObjectName("label_Auth");
        label_Auth->setGeometry(QRect(130, 30, 347, 78));
        label_Auth->setStyleSheet(QString::fromUtf8("font: italic 42pt \"Comic Sans MS\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(239, 255, 246);"));
        layoutWidget = new QWidget(widget_down);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 160, 501, 115));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_Username = new QLineEdit(layoutWidget);
        lineEdit_Username->setObjectName("lineEdit_Username");
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        lineEdit_Username->setFont(font);
        lineEdit_Username->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 0, 83);\n"
"color: rgb(255, 255, 255);\n"
"border: 2px solid rgb(212, 255, 254);\n"
"border-top: 0px;\n"
"border-left: 0px;\n"
"border-right: 0px;"));
        lineEdit_Username->setMaxLength(50);

        verticalLayout->addWidget(lineEdit_Username);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setFont(font);
        lineEdit_Password->setFocusPolicy(Qt::ClickFocus);
        lineEdit_Password->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 0, 83);\n"
"color: rgb(255, 255, 255);\n"
"border: 2px solid rgb(212, 255, 254);\n"
"border-top: 0px;\n"
"border-left: 0px;\n"
"border-right: 0px;"));
        lineEdit_Password->setMaxLength(50);
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_Password);

        label_Error = new QLabel(widget_down);
        label_Error->setObjectName("label_Error");
        label_Error->setGeometry(QRect(80, 120, 441, 27));
        label_Error->setMinimumSize(QSize(441, 27));
        label_Error->setMaximumSize(QSize(441, 27));
        label_Error->setStyleSheet(QString::fromUtf8("background-color: rgba(29, 119, 255, 0);\n"
"color: rgb(255, 133, 135);\n"
"font: italic 14pt \"Comic Sans MS\";\n"
"\n"
""));
        label_Error->setAlignment(Qt::AlignCenter);

        retranslateUi(Auth);

        QMetaObject::connectSlotsByName(Auth);
    } // setupUi

    void retranslateUi(QWidget *Auth)
    {
        Auth->setWindowTitle(QCoreApplication::translate("Auth", "QuickDialog", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Auth->setToolTip(QCoreApplication::translate("Auth", "<html><head/><body><p>\320\222\321\205\320\276\320\264 \320\262 \320\260\320\272\320\272\320\260\321\203\320\275\321\202 \321\201 \320\262\320\262\320\265\320\264\321\221\320\275\320\275\321\213\320\274\320\270 \321\203\321\207\321\221\321\202\320\275\321\213\320\274\320\270 \320\264\320\260\320\275\320\275\321\213\320\274\320\270</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Auth->setText(QCoreApplication::translate("Auth", "\320\222\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Registr->setToolTip(QCoreApplication::translate("Auth", "<html><head/><body><p>\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\275\320\276\320\262\320\276\320\263\320\276 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260 \320\277\320\276 \320\262\320\262\320\265\320\264\321\221\320\275\320\275\321\213\320\274 \321\203\321\207\321\221\321\202\320\275\321\213\320\274 \320\264\320\260\320\275\320\275\321\213\320\274</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Registr->setText(QCoreApplication::translate("Auth", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_Auth->setText(QCoreApplication::translate("Auth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        lineEdit_Username->setPlaceholderText(QCoreApplication::translate("Auth", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("Auth", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_Error->setText(QCoreApplication::translate("Auth", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214 \321\201 \321\202\320\260\320\272\320\270\320\274 \320\270\320\274\320\265\320\275\320\265\320\274 \321\203\320\266\320\265 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Auth: public Ui_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
