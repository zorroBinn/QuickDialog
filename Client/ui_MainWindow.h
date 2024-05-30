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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGroupBox *groupBox_main;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_connect;
    QLineEdit *lineEdit;
    QPushButton *pushButton_send;
    QWidget *widget_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(918, 674);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        groupBox_main = new QGroupBox(widget);
        groupBox_main->setObjectName("groupBox_main");
        groupBox_main->setGeometry(QRect(20, 190, 276, 289));
        gridLayout = new QGridLayout(groupBox_main);
        gridLayout->setObjectName("gridLayout");
        textBrowser = new QTextBrowser(groupBox_main);
        textBrowser->setObjectName("textBrowser");

        gridLayout->addWidget(textBrowser, 1, 0, 1, 3);

        pushButton_connect = new QPushButton(groupBox_main);
        pushButton_connect->setObjectName("pushButton_connect");

        gridLayout->addWidget(pushButton_connect, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_main);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 2, 0, 1, 2);

        pushButton_send = new QPushButton(groupBox_main);
        pushButton_send->setObjectName("pushButton_send");

        gridLayout->addWidget(pushButton_send, 2, 2, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");

        gridLayout_2->addWidget(widget_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_main->setTitle(QCoreApplication::translate("MainWindow", "QuickDialog", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
