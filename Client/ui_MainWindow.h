/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_search;
    QListView *listView_chats;
    QGroupBox *groupBox_main;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_mess;
    QPushButton *pushButton_send;
    QPushButton *pushButton_connect;
    QTextBrowser *textBrowser_current_chat;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(923, 683);
        MainWindow->setMinimumSize(QSize(750, 400));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("contact-new")));
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(24, 0, 36, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_search = new QLineEdit(centralwidget);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setMinimumSize(QSize(300, 50));
        lineEdit_search->setMaximumSize(QSize(300, 50));
        lineEdit_search->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 65);\n"
"color: rgb(238, 255, 246);\n"
"font: 700 24pt \"Comic Sans MS\";\n"
"border: 2px solid rgb(167, 151, 255);\n"
"border-top: 0px;\n"
"border-left: 0px;\n"
"border-right: 0px;"));
        lineEdit_search->setMaxLength(100);

        verticalLayout->addWidget(lineEdit_search);

        listView_chats = new QListView(centralwidget);
        listView_chats->setObjectName("listView_chats");
        listView_chats->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout->addWidget(listView_chats);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        groupBox_main = new QGroupBox(centralwidget);
        groupBox_main->setObjectName("groupBox_main");
        groupBox_main->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border: 0px"));
        gridLayout = new QGridLayout(groupBox_main);
        gridLayout->setObjectName("gridLayout");
        lineEdit_mess = new QLineEdit(groupBox_main);
        lineEdit_mess->setObjectName("lineEdit_mess");
        lineEdit_mess->setMinimumSize(QSize(0, 50));
        lineEdit_mess->setMaximumSize(QSize(16777215, 50));
        lineEdit_mess->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 65);\n"
"font: 700 24pt \"Comic Sans MS\";\n"
"color: rgb(242, 255, 244);\n"
"border: 2px solid rgb(0, 0, 255);\n"
"border-top: 0px;\n"
"border-left: 0px;\n"
"border-right: 0px;\n"
""));

        gridLayout->addWidget(lineEdit_mess, 2, 0, 1, 2);

        pushButton_send = new QPushButton(groupBox_main);
        pushButton_send->setObjectName("pushButton_send");
        pushButton_send->setMinimumSize(QSize(50, 50));
        pushButton_send->setMaximumSize(QSize(50, 50));
        pushButton_send->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_send->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0.488636 rgba(80, 0, 122, 255), stop:0.806818 rgba(44, 18, 97, 255));\n"
"font: 700 40pt \"Times New Roman\";\n"
"color: rgb(198, 255, 255);\n"
"border: 2px solid rgb(0, 255, 255);"));

        gridLayout->addWidget(pushButton_send, 2, 2, 1, 1);

        pushButton_connect = new QPushButton(groupBox_main);
        pushButton_connect->setObjectName("pushButton_connect");
        pushButton_connect->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(pushButton_connect, 0, 0, 1, 1);

        textBrowser_current_chat = new QTextBrowser(groupBox_main);
        textBrowser_current_chat->setObjectName("textBrowser_current_chat");
        textBrowser_current_chat->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 60);\n"
"color: rgb(239, 253, 255);\n"
"font: 700 18pt \"Comic Sans MS\";\n"
"border: 0px"));

        gridLayout->addWidget(textBrowser_current_chat, 1, 0, 1, 3);


        formLayout->setWidget(0, QFormLayout::FieldRole, groupBox_main);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QuickDialog", nullptr));
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\270\320\274\320\265\320\275\320\270", nullptr));
        groupBox_main->setTitle(QString());
        lineEdit_mess->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\321\221 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
