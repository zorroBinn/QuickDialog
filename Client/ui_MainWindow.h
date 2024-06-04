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
#include <QtWidgets/QSplitter>
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
    QSplitter *splitter;
    QPushButton *pushButton_NewChat;
    QLineEdit *lineEdit_Search;
    QListView *listView_Chats;
    QGroupBox *groupBox_Chat;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Chat_NewUser;
    QPushButton *pushButton_Send;
    QTextBrowser *textBrowser_CurrentChat;
    QLineEdit *lineEdit_Mess;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1032, 706);
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
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        pushButton_NewChat = new QPushButton(splitter);
        pushButton_NewChat->setObjectName("pushButton_NewChat");
        pushButton_NewChat->setMinimumSize(QSize(50, 50));
        pushButton_NewChat->setMaximumSize(QSize(50, 50));
        pushButton_NewChat->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_NewChat->setFocusPolicy(Qt::ClickFocus);
        pushButton_NewChat->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0.488636 rgba(80, 0, 122, 255), stop:0.806818 rgba(44, 18, 97, 255));\n"
"font: 700 40pt \"Times New Roman\";\n"
"color: rgb(198, 255, 255);\n"
"border: 2px solid rgb(0, 0, 190);"));
        splitter->addWidget(pushButton_NewChat);
        lineEdit_Search = new QLineEdit(splitter);
        lineEdit_Search->setObjectName("lineEdit_Search");
        lineEdit_Search->setMinimumSize(QSize(250, 50));
        lineEdit_Search->setMaximumSize(QSize(250, 50));
        lineEdit_Search->setFocusPolicy(Qt::ClickFocus);
        lineEdit_Search->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 65);\n"
"color: rgb(238, 255, 246);\n"
"font: 700 20pt \"Comic Sans MS\";\n"
"border: 2px solid rgb(167, 151, 255);\n"
"border-top: 0px;\n"
"border-left: 0px;\n"
"border-right: 0px;"));
        lineEdit_Search->setMaxLength(100);
        splitter->addWidget(lineEdit_Search);

        verticalLayout->addWidget(splitter);

        listView_Chats = new QListView(centralwidget);
        listView_Chats->setObjectName("listView_Chats");
        listView_Chats->setFocusPolicy(Qt::NoFocus);
        listView_Chats->setStyleSheet(QString::fromUtf8("border: none"));
        listView_Chats->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout->addWidget(listView_Chats);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        groupBox_Chat = new QGroupBox(centralwidget);
        groupBox_Chat->setObjectName("groupBox_Chat");
        groupBox_Chat->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border: 0px"));
        gridLayout = new QGridLayout(groupBox_Chat);
        gridLayout->setObjectName("gridLayout");
        pushButton_Chat_NewUser = new QPushButton(groupBox_Chat);
        pushButton_Chat_NewUser->setObjectName("pushButton_Chat_NewUser");
        pushButton_Chat_NewUser->setMinimumSize(QSize(200, 35));
        pushButton_Chat_NewUser->setMaximumSize(QSize(200, 35));
        pushButton_Chat_NewUser->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Chat_NewUser->setFocusPolicy(Qt::ClickFocus);
        pushButton_Chat_NewUser->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 74);\n"
"font: 700 16pt \"Times New Roman\";\n"
"color: rgb(198, 255, 255);\n"
"border: 2px solid rgb(0, 0, 190);"));

        gridLayout->addWidget(pushButton_Chat_NewUser, 1, 1, 1, 1);

        pushButton_Send = new QPushButton(groupBox_Chat);
        pushButton_Send->setObjectName("pushButton_Send");
        pushButton_Send->setMinimumSize(QSize(50, 50));
        pushButton_Send->setMaximumSize(QSize(50, 50));
        pushButton_Send->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Send->setFocusPolicy(Qt::ClickFocus);
        pushButton_Send->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0.488636 rgba(80, 0, 122, 255), stop:0.806818 rgba(44, 18, 97, 255));\n"
"font: 700 40pt \"Times New Roman\";\n"
"color: rgb(198, 255, 255);\n"
"border: 2px solid rgb(0, 255, 255);"));

        gridLayout->addWidget(pushButton_Send, 3, 2, 1, 1);

        textBrowser_CurrentChat = new QTextBrowser(groupBox_Chat);
        textBrowser_CurrentChat->setObjectName("textBrowser_CurrentChat");
        textBrowser_CurrentChat->setFocusPolicy(Qt::NoFocus);
        textBrowser_CurrentChat->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 60);\n"
"color: rgb(239, 253, 255);\n"
"font: 700 18pt \"Comic Sans MS\";\n"
"border: 0px"));

        gridLayout->addWidget(textBrowser_CurrentChat, 2, 0, 1, 3);

        lineEdit_Mess = new QLineEdit(groupBox_Chat);
        lineEdit_Mess->setObjectName("lineEdit_Mess");
        lineEdit_Mess->setMinimumSize(QSize(0, 50));
        lineEdit_Mess->setMaximumSize(QSize(16777215, 50));
        lineEdit_Mess->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 65);\n"
"font: 700 24pt \"Comic Sans MS\";\n"
"color: rgb(242, 255, 244);\n"
"border: 2px solid rgb(0, 0, 255);\n"
"border-top: 0px;\n"
"border-left: 0px;\n"
"border-right: 0px;\n"
""));

        gridLayout->addWidget(lineEdit_Mess, 3, 0, 1, 2);


        formLayout->setWidget(0, QFormLayout::FieldRole, groupBox_Chat);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QuickDialog", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_NewChat->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\263\321\200\321\203\320\277\320\277\320\276\320\262\320\276\320\271 \321\207\320\260\321\202</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_NewChat->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_Search->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\237\320\276\320\270\321\201\320\272 \321\207\320\265\320\273\320\276\320\262\320\265\320\272\320\260 \320\277\320\276 \320\275\320\270\320\272\320\275\320\265\320\271\320\274\321\203</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_Search->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\270\320\274\320\265\320\275\320\270", nullptr));
        groupBox_Chat->setTitle(QString());
#if QT_CONFIG(tooltip)
        pushButton_Chat_NewUser->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\260 \320\262 \320\263\321\200\321\203\320\277\320\277\320\276\320\262\320\276\320\271 \321\207\320\260\321\202</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Chat_NewUser->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\260", nullptr));
        pushButton_Send->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        lineEdit_Mess->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\321\221 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
