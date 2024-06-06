#include "NewChat.h"
#include "ui_NewChat.h"
#include <QDebug>

NewChat::NewChat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewChat)
{
    ui->setupUi(this);
}

NewChat::~NewChat()
{
    delete ui;
}

//Получение списка пользователей (кроме текущего)
void NewChat::GetUsersList(QStringList users)
{
    //Создаём новые checkable элементы в QlistWidget
    foreach (const QString &user, users) {
        QListWidgetItem *newitem = new QListWidgetItem(user);
        newitem->setFlags(newitem->flags() | Qt::ItemIsUserCheckable);
        newitem->setCheckState(Qt::Unchecked);
        ui->listWidget_AllUsers->addItem(newitem);
        UserCheckStates[user] = Qt::Unchecked;
    }
    ui->lineEdit_Search->setText(" ");
    ui->lineEdit_Search->setText("");
}

//Создание нового чата
void NewChat::on_pushButton_CreateChat_clicked()
{
    if(ui->lineEdit_ChatName->text().trimmed() != "")
    {
        QStringList selectedusers; //Отмеченные пользователи
        ui->lineEdit_Search->setText("");
        for(int i = 0; i < ui->listWidget_AllUsers->count(); ++i) {
            QListWidgetItem *item = ui->listWidget_AllUsers->item(i);
            if(item->checkState() == Qt::Checked) {
                selectedusers << item->text();
            }
        }
        QString chatname = ui->lineEdit_ChatName->text(); //Название чата
        emit createNewChat(selectedusers, chatname);
        this->close();
    }
    else
    {
        ui->lineEdit_ChatName->setStyleSheet("border: 1px solid red; "
                                             "color: rgb(234, 255, 252); "
                                             "background-color: rgb(0, 0, 70); "
                                             "font: italic 14pt \"Comic Sans MS\";");
    }
}

//Поиск пользователей
void NewChat::on_lineEdit_Search_textChanged(const QString &arg1)
{
    // Сохранение текущих состояний флажков
    for(int i = 0; i < ui->listWidget_AllUsers->count(); ++i) {
        QListWidgetItem *item = ui->listWidget_AllUsers->item(i);
        UserCheckStates[item->text()] = item->checkState();
    }
    ui->listWidget_AllUsers->clear();
    //Поиск среди пользователей, включающих в username строку из lineEdit_Search
    for(auto it = UserCheckStates.begin(); it != UserCheckStates.end(); ++it) {
        const QString &user = it.key();
        // Если имя пользователя содержит введенный текст, добавляем его в список
        if (user.contains(arg1, Qt::CaseInsensitive)) {
            QListWidgetItem *newitem = new QListWidgetItem(user);
            newitem->setFlags(newitem->flags() | Qt::ItemIsUserCheckable);
            newitem->setCheckState(it.value()); // Восстановлено
            ui->listWidget_AllUsers->addItem(newitem);
        }
    }
}

//При закрытии формы - очищаем её
void NewChat::closeEvent(QCloseEvent *event)
{
    ui->lineEdit_ChatName->setStyleSheet("border: 1px solid rgb(0, 0, 255); "
                                         "color: rgb(234, 255, 252); "
                                         "background-color: rgb(0, 0, 70); "
                                         "font: italic 14pt \"Comic Sans MS\";");
    UserCheckStates.clear();
    ui->listWidget_AllUsers->clear();
    ui->lineEdit_ChatName->clear();
    ui->lineEdit_Search->clear();
    emit thisClosed();
    event->accept();
}


