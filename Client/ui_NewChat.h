/********************************************************************************
** Form generated from reading UI file 'NewChat.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCHAT_H
#define UI_NEWCHAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewChat
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_ChatName;
    QGroupBox *groupBox_AddUsers;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_Search;
    QListWidget *listWidget_AllUsers;
    QPushButton *pushButton_CreateChat;

    void setupUi(QWidget *NewChat)
    {
        if (NewChat->objectName().isEmpty())
            NewChat->setObjectName("NewChat");
        NewChat->resize(350, 500);
        NewChat->setMinimumSize(QSize(350, 500));
        NewChat->setMaximumSize(QSize(350, 500));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("contact-new")));
        NewChat->setWindowIcon(icon);
        NewChat->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(24, 0, 36, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));"));
        gridLayout = new QGridLayout(NewChat);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEdit_ChatName = new QLineEdit(NewChat);
        lineEdit_ChatName->setObjectName("lineEdit_ChatName");
        lineEdit_ChatName->setFocusPolicy(Qt::StrongFocus);
        lineEdit_ChatName->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(0, 0, 255);\n"
"color: rgb(234, 255, 252);\n"
"background-color: rgb(0, 0, 70);\n"
"font: italic 14pt \"Comic Sans MS\";"));
        lineEdit_ChatName->setMaxLength(23);

        verticalLayout_2->addWidget(lineEdit_ChatName);

        groupBox_AddUsers = new QGroupBox(NewChat);
        groupBox_AddUsers->setObjectName("groupBox_AddUsers");
        groupBox_AddUsers->setFocusPolicy(Qt::NoFocus);
        groupBox_AddUsers->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: rgb(234, 255, 252);\n"
"font: italic 14pt \"Comic Sans MS\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        groupBox_AddUsers->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox_AddUsers);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        lineEdit_Search = new QLineEdit(groupBox_AddUsers);
        lineEdit_Search->setObjectName("lineEdit_Search");
        lineEdit_Search->setFocusPolicy(Qt::ClickFocus);
        lineEdit_Search->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(0, 0, 255);\n"
"color: rgb(234, 255, 252);\n"
"background-color: rgb(0, 0, 70);\n"
"font: italic 14pt \"Comic Sans MS\";"));

        verticalLayout->addWidget(lineEdit_Search);

        listWidget_AllUsers = new QListWidget(groupBox_AddUsers);
        listWidget_AllUsers->setObjectName("listWidget_AllUsers");
        listWidget_AllUsers->setFocusPolicy(Qt::NoFocus);
        listWidget_AllUsers->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(0, 0, 190)"));
        listWidget_AllUsers->setSortingEnabled(true);

        verticalLayout->addWidget(listWidget_AllUsers);


        verticalLayout_2->addWidget(groupBox_AddUsers);

        pushButton_CreateChat = new QPushButton(NewChat);
        pushButton_CreateChat->setObjectName("pushButton_CreateChat");
        pushButton_CreateChat->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_CreateChat->setFocusPolicy(Qt::NoFocus);
        pushButton_CreateChat->setStyleSheet(QString::fromUtf8("font: italic 24pt \"Comic Sans MS\";\n"
"color: rgb(234, 253, 255);\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(24, 0, 36, 255), stop:0.312849 rgba(38, 8, 72, 255), stop:0.731844 rgba(44, 18, 97, 255), stop:1 rgba(50, 29, 125, 255));\n"
"border: 1px solid rgb(0, 0, 190)"));

        verticalLayout_2->addWidget(pushButton_CreateChat);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(NewChat);

        QMetaObject::connectSlotsByName(NewChat);
    } // setupUi

    void retranslateUi(QWidget *NewChat)
    {
        NewChat->setWindowTitle(QCoreApplication::translate("NewChat", "QuickDialog", nullptr));
        lineEdit_ChatName->setPlaceholderText(QCoreApplication::translate("NewChat", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\207\320\260\321\202\320\260", nullptr));
        groupBox_AddUsers->setTitle(QCoreApplication::translate("NewChat", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\276\320\262", nullptr));
        lineEdit_Search->setPlaceholderText(QCoreApplication::translate("NewChat", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\270\320\274\320\265\320\275\320\270", nullptr));
        pushButton_CreateChat->setText(QCoreApplication::translate("NewChat", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\207\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewChat: public Ui_NewChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCHAT_H
