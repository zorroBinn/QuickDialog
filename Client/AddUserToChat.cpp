#include "AddUserToChat.h"
#include "ui_AddUserToChat.h"

AddUserToChat::AddUserToChat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddUserToChat)
{
    ui->setupUi(this);
}

AddUserToChat::~AddUserToChat()
{
    delete ui;
}

//Получение списка доступных к приглашению пользователей
void AddUserToChat::getUsersList(QStringList users)
{
    newChatUsersCheckStates.clear();
    ui->listWidget_AddUser->clear();
    //Создаём новые checkable элементы в QlistWidget
    foreach (const QString &user, users) {
        if(participants.contains(user)) continue;
        QListWidgetItem *newitem = new QListWidgetItem(user);
        newitem->setFlags(newitem->flags() | Qt::ItemIsUserCheckable);
        newitem->setCheckState(Qt::Unchecked);
        ui->listWidget_AddUser->addItem(newitem);
        newChatUsersCheckStates[user] = Qt::Unchecked;
    }
}

//Получение списка участников чата, его названия и Id
void AddUserToChat::getParticipantsList(QStringList participants, QString chatname, int chatId)
{
    this->participants = participants;
    currentChatName = chatname;
    ui->label_ChatName->setText(currentChatName);
    currentChatId = chatId;
    ui->listWidget_Participants->clear();
    foreach (const QString &user, this->participants) {
        QListWidgetItem *newitem = new QListWidgetItem(user);
        ui->listWidget_Participants->addItem(newitem);
    }
}

void AddUserToChat::on_pushButton_AddUsers_clicked()
{
    //Сохранение текущих состояний флажков
    ui->lineEdit_Search->setText("");
    for(int i = 0; i < ui->listWidget_AddUser->count(); i++) {
        QListWidgetItem *item = ui->listWidget_AddUser->item(i);
        newChatUsersCheckStates[item->text()] = item->checkState();
    }
    bool isSelected = false; //Для проверки наличия хотя бы 1 выбранного нового участника
    foreach(Qt::CheckState state, newChatUsersCheckStates) {
        if(state == Qt::Checked)
        {
            isSelected = true;
            break;
        }
    }
    //Если хотя выбран хотя бы 1 новый участник - делаем запрос на добавление
    if(isSelected)
    {
        QStringList selectedusers; //Отмеченные пользователи
        ui->lineEdit_Search->setText("");
        for(int i = 0; i < ui->listWidget_AddUser->count(); i++) {
            QListWidgetItem *item = ui->listWidget_AddUser->item(i);
            if(item->checkState() == Qt::Checked) {
                selectedusers << item->text();
            }
        }
        emit addUser(selectedusers, currentChatId);
    }
    this->close();
}


void AddUserToChat::on_lineEdit_Search_textChanged(const QString &arg1)
{
    //Сохранение текущих состояний флажков
    for(int i = 0; i < ui->listWidget_AddUser->count(); i++) {
        QListWidgetItem *item = ui->listWidget_AddUser->item(i);
        newChatUsersCheckStates[item->text()] = item->checkState();
    }
    ui->listWidget_AddUser->clear();
    //Поиск среди пользователей, включающих в username строку из lineEdit_Search
    for(auto it = newChatUsersCheckStates.begin(); it != newChatUsersCheckStates.end(); ++it) {
        const QString &user = it.key();
        //Если имя пользователя содержит введенный текст, добавляем его в список
        if (user.contains(arg1, Qt::CaseInsensitive)) {
            QListWidgetItem *newitem = new QListWidgetItem(user);
            newitem->setFlags(newitem->flags() | Qt::ItemIsUserCheckable);
            newitem->setCheckState(it.value());
            ui->listWidget_AddUser->addItem(newitem);
        }
    }
}

//Очистка формы при закрытии
void AddUserToChat::closeEvent(QCloseEvent *event)
{
    participants.clear();
    newChatUsersCheckStates.clear();
    ui->listWidget_Participants->clear();
    ui->lineEdit_Search->setText("");
    emit thisClosed();
    event->accept();
}

