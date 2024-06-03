/********************************************************************************
** Form generated from reading UI file 'AddUserToChat.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERTOCHAT_H
#define UI_ADDUSERTOCHAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddUserToChat
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_ChatName;
    QGroupBox *groupBox_Participants;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea_Participants;
    QWidget *scrollAreaWidgetContents;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_AddUser;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_Search;
    QScrollArea *scrollArea_Users;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *pushButton_AddUsers;

    void setupUi(QWidget *AddUserToChat)
    {
        if (AddUserToChat->objectName().isEmpty())
            AddUserToChat->setObjectName("AddUserToChat");
        AddUserToChat->resize(350, 600);
        AddUserToChat->setMinimumSize(QSize(350, 600));
        AddUserToChat->setMaximumSize(QSize(350, 600));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("contact-new")));
        AddUserToChat->setWindowIcon(icon);
        AddUserToChat->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(24, 0, 36, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));"));
        verticalLayout_2 = new QVBoxLayout(AddUserToChat);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_ChatName = new QLabel(AddUserToChat);
        label_ChatName->setObjectName("label_ChatName");
        label_ChatName->setFocusPolicy(Qt::NoFocus);
        label_ChatName->setStyleSheet(QString::fromUtf8("font: italic 18pt \"Comic Sans MS\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(239, 255, 246);"));
        label_ChatName->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_ChatName);

        groupBox_Participants = new QGroupBox(AddUserToChat);
        groupBox_Participants->setObjectName("groupBox_Participants");
        groupBox_Participants->setFocusPolicy(Qt::NoFocus);
        groupBox_Participants->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: rgb(234, 255, 252);\n"
"font: italic 14pt \"Comic Sans MS\";"));
        groupBox_Participants->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(groupBox_Participants);
        gridLayout->setObjectName("gridLayout");
        scrollArea_Participants = new QScrollArea(groupBox_Participants);
        scrollArea_Participants->setObjectName("scrollArea_Participants");
        scrollArea_Participants->setFocusPolicy(Qt::NoFocus);
        scrollArea_Participants->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(0, 0, 127);"));
        scrollArea_Participants->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 312, 207));
        scrollArea_Participants->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea_Participants, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_Participants);

        groupBox_AddUser = new QGroupBox(AddUserToChat);
        groupBox_AddUser->setObjectName("groupBox_AddUser");
        groupBox_AddUser->setFocusPolicy(Qt::NoFocus);
        groupBox_AddUser->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: rgb(234, 255, 252);\n"
"font: italic 14pt \"Comic Sans MS\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        groupBox_AddUser->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox_AddUser);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        lineEdit_Search = new QLineEdit(groupBox_AddUser);
        lineEdit_Search->setObjectName("lineEdit_Search");
        lineEdit_Search->setFocusPolicy(Qt::StrongFocus);
        lineEdit_Search->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(0, 0, 255);\n"
"color: rgb(234, 255, 252);\n"
"background-color: rgb(0, 0, 70);\n"
"font: italic 14pt \"Comic Sans MS\";"));

        verticalLayout->addWidget(lineEdit_Search);

        scrollArea_Users = new QScrollArea(groupBox_AddUser);
        scrollArea_Users->setObjectName("scrollArea_Users");
        scrollArea_Users->setFocusPolicy(Qt::ClickFocus);
        scrollArea_Users->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(0, 0, 127);"));
        scrollArea_Users->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 312, 169));
        scrollArea_Users->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_Users);


        verticalLayout_2->addWidget(groupBox_AddUser);

        pushButton_AddUsers = new QPushButton(AddUserToChat);
        pushButton_AddUsers->setObjectName("pushButton_AddUsers");
        pushButton_AddUsers->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_AddUsers->setFocusPolicy(Qt::ClickFocus);
        pushButton_AddUsers->setStyleSheet(QString::fromUtf8("font: italic 24pt \"Comic Sans MS\";\n"
"color: rgb(234, 253, 255);\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(24, 0, 36, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));\n"
"border: 1px solid rgb(0, 0, 190)"));

        verticalLayout_2->addWidget(pushButton_AddUsers);


        retranslateUi(AddUserToChat);

        QMetaObject::connectSlotsByName(AddUserToChat);
    } // setupUi

    void retranslateUi(QWidget *AddUserToChat)
    {
        AddUserToChat->setWindowTitle(QCoreApplication::translate("AddUserToChat", "QuickDialog", nullptr));
        label_ChatName->setText(QCoreApplication::translate("AddUserToChat", "ChatName(23)", nullptr));
        groupBox_Participants->setTitle(QCoreApplication::translate("AddUserToChat", "\320\243\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\270", nullptr));
        groupBox_AddUser->setTitle(QCoreApplication::translate("AddUserToChat", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        lineEdit_Search->setPlaceholderText(QCoreApplication::translate("AddUserToChat", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\270\320\274\320\265\320\275\320\270", nullptr));
        pushButton_AddUsers->setText(QCoreApplication::translate("AddUserToChat", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddUserToChat: public Ui_AddUserToChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERTOCHAT_H
