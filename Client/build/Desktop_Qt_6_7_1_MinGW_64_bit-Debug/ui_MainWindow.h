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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab_auth;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_auth;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_registr;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_registr;
    QLineEdit *lineEdit_auth_password;
    QLineEdit *lineEdit_auth_password_replay;
    QPushButton *pushButton_auth;
    QLabel *label_auth_error;
    QLabel *label_auth_username;
    QLineEdit *lineEdit_auth_username;
    QLabel *label_auth_password;
    QLabel *label_auth_password_replay;
    QWidget *tab_main;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_main;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_connect;
    QLineEdit *lineEdit;
    QPushButton *pushButton_send;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(450, 347);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_6 = new QGridLayout(centralwidget);
        gridLayout_6->setObjectName("gridLayout_6");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setContextMenuPolicy(Qt::NoContextMenu);
        tabWidget->setAcceptDrops(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(5, 5));
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setTabBarAutoHide(false);
        tab_auth = new QWidget();
        tab_auth->setObjectName("tab_auth");
        gridLayout_4 = new QGridLayout(tab_auth);
        gridLayout_4->setObjectName("gridLayout_4");
        groupBox_auth = new QGroupBox(tab_auth);
        groupBox_auth->setObjectName("groupBox_auth");
        gridLayout_2 = new QGridLayout(groupBox_auth);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(9, -1, -1, -1);
        groupBox_registr = new QGroupBox(groupBox_auth);
        groupBox_registr->setObjectName("groupBox_registr");
        gridLayout_3 = new QGridLayout(groupBox_registr);
        gridLayout_3->setObjectName("gridLayout_3");
        pushButton_registr = new QPushButton(groupBox_registr);
        pushButton_registr->setObjectName("pushButton_registr");

        gridLayout_3->addWidget(pushButton_registr, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_registr, 5, 1, 1, 1);

        lineEdit_auth_password = new QLineEdit(groupBox_auth);
        lineEdit_auth_password->setObjectName("lineEdit_auth_password");
        lineEdit_auth_password->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_auth_password, 1, 1, 1, 1);

        lineEdit_auth_password_replay = new QLineEdit(groupBox_auth);
        lineEdit_auth_password_replay->setObjectName("lineEdit_auth_password_replay");
        lineEdit_auth_password_replay->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_auth_password_replay, 2, 1, 1, 1);

        pushButton_auth = new QPushButton(groupBox_auth);
        pushButton_auth->setObjectName("pushButton_auth");

        gridLayout_2->addWidget(pushButton_auth, 4, 1, 1, 1);

        label_auth_error = new QLabel(groupBox_auth);
        label_auth_error->setObjectName("label_auth_error");

        gridLayout_2->addWidget(label_auth_error, 3, 1, 1, 1);

        label_auth_username = new QLabel(groupBox_auth);
        label_auth_username->setObjectName("label_auth_username");

        gridLayout_2->addWidget(label_auth_username, 0, 0, 1, 1);

        lineEdit_auth_username = new QLineEdit(groupBox_auth);
        lineEdit_auth_username->setObjectName("lineEdit_auth_username");
        lineEdit_auth_username->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_auth_username, 0, 1, 1, 1);

        label_auth_password = new QLabel(groupBox_auth);
        label_auth_password->setObjectName("label_auth_password");

        gridLayout_2->addWidget(label_auth_password, 1, 0, 1, 1);

        label_auth_password_replay = new QLabel(groupBox_auth);
        label_auth_password_replay->setObjectName("label_auth_password_replay");

        gridLayout_2->addWidget(label_auth_password_replay, 2, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_auth, 0, 0, 1, 1);

        tabWidget->addTab(tab_auth, QString());
        tab_main = new QWidget();
        tab_main->setObjectName("tab_main");
        gridLayout_5 = new QGridLayout(tab_main);
        gridLayout_5->setObjectName("gridLayout_5");
        groupBox_main = new QGroupBox(tab_main);
        groupBox_main->setObjectName("groupBox_main");
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


        gridLayout_5->addWidget(groupBox_main, 0, 0, 1, 1);

        tabWidget->addTab(tab_main, QString());

        gridLayout_6->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_auth->setTitle(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        groupBox_registr->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260?", nullptr));
        pushButton_registr->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        pushButton_auth->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264", nullptr));
        label_auth_error->setText(QString());
        label_auth_username->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_auth_password->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_auth_password_replay->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_auth), QString());
        groupBox_main->setTitle(QCoreApplication::translate("MainWindow", "QuickDialog", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_main), QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
