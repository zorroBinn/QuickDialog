#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

//Конструктор основной формы
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    socket->connectToHost("192.168.1.103", 2024);

    authform = new Auth(); //Окно авторизации
    authform->show();
    connect(authform, &Auth::registerUser, this, &MainWindow::registerUser);
    connect(authform, &Auth::authUser, this, &MainWindow::authUser);

    newChat = new NewChat(); //Окно создания нового чата
    connect(newChat, &NewChat::thisClosed, this, &MainWindow::newChatDestroyed);
    connect(newChat, &NewChat::createNewChat, this, &MainWindow::createNewChat);

    addUserToChat = new AddUserToChat();
    connect(addUserToChat, &AddUserToChat::thisClosed, this, &MainWindow::addUserToChatDestroyed);

    ui->pushButton_Chat_NewUser->setVisible(false);
}

//Деструктор
MainWindow::~MainWindow()
{
    delete ui;
    delete this->newChat;
    delete this->addUserToChat;
}

void MainWindow::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::UserMessage << str;
    socket->write(Data);
    ui->lineEdit_Mess->clear();
}

//Запрос на получение списка всех пользователей
void MainWindow::GetAllUsers()
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::GetAllUsers;
    socket->write(Data);
}

//Запрос на получение списка всех чатов, в которых участвует пользователь
void MainWindow::GetChats()
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::GetChats;
    socket->write(Data);
}

//Запрос на получение списка пользователей текущего чата
void MainWindow::getChatParticipants(int chatId)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::GetChatParticipants << chatId;
    socket->write(Data);
}

//Получает список всех пользователей содержащих в username строку из поиска контактов
void MainWindow::showUsersInChatList(QStringList users)
{
    if(searchKey != "")
    {
        ui->listWidget_Chats->clear();
        currentChatId = 0;
        currentChatName = "";
        ui->label_CurrentChatName->setVisible(false);
        foreach (const QString &user, users) {
            if (!user.contains(searchKey, Qt::CaseInsensitive)) continue;
            QListWidgetItem *newitem = new QListWidgetItem(user);
            ui->listWidget_Chats->addItem(newitem);
        }
    }
}

//Получение информации от сервера и  распознавание его типа
void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok) {
        ClientSignalType type;
        in >> type;

        switch(type)
        {
        case ClientSignalType::AuthDone:
        {
            in >> Username;
            authform->close();
            this->show();
            GetChats();
            break;
        }
        case ClientSignalType::AuthError:
        {
            connect(this, &MainWindow::AuthError, authform, &Auth::AuthError);
            emit AuthError();
            break;
        }
        case ClientSignalType::GetAllUsers:
        {
            QStringList users;
            in >> users;
            if(!isThisActive)
            {
                connect(this, &MainWindow::allUsers, newChat, &NewChat::GetUsersList);
                emit allUsers(users);
            }
            else
            {
                showUsersInChatList(users);
            }
            break;
        }
        case ClientSignalType::GetChats:
        {
            in >> chats;
            ui->listWidget_Chats->clear();
            foreach (const QString &chatname, chats) {
                ui->listWidget_Chats->addItem(new QListWidgetItem(chatname));
            }
            break;
        }
        case ClientSignalType::GetChatParticipants:
        {
            QStringList participants;
            in >> participants;
            if(!isThisActive)
            {
                connect(this, &MainWindow::chatParticipants, addUserToChat, &AddUserToChat::getParticipantsList);
                emit chatParticipants(participants, currentChatName);
            }
            break;
        }
        }
    }
}

//Запрос на регистрацию нового пользователя
void MainWindow::registerUser(const QString &username, const QString &password)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::Registration << username << password;
    socket->write(Data);
}

//Запрос на аутентификацию пользователя
void MainWindow::authUser(const QString &username, const QString &password)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::Authentication << username << password;
    socket->write(Data);
}

//Запрос на создание нового чата
void MainWindow::createNewChat(QStringList users, const QString &chatname)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::CreateNewChat << users << chatname;
    socket->write(Data);
}

//При закрытии окна создания нового чата - сделать основное окно активным
void MainWindow::newChatDestroyed()
{
    this->setDisabled(false);
    isThisActive = true;
    //ui->lineEdit_Search->setText("");
    //on_lineEdit_Search_textEdited("");
}

//При закрытии окна добавления пользователя в чат - сделать основное окно активным
void MainWindow::addUserToChatDestroyed()
{
    this->setDisabled(false);
    isThisActive = true;
    //ui->lineEdit_Search->setText("");
    //on_lineEdit_Search_textEdited("");
}


void MainWindow::on_pushButton_Send_clicked()
{
    if(ui->lineEdit_Mess->text().trimmed() != "") SendToServer(ui->lineEdit_Mess->text().trimmed());
}


void MainWindow::on_lineEdit_Mess_returnPressed()
{
    if(ui->lineEdit_Mess->text().trimmed() != "") SendToServer(ui->lineEdit_Mess->text());
}


void MainWindow::on_pushButton_Chat_NewUser_clicked()
{
    isThisActive = false;
    ui->lineEdit_Search->setText("");
    searchKey = "";
    addUserToChat->show();
    this->setDisabled(true);
    getChatParticipants(currentChatId);
}


void MainWindow::on_pushButton_NewChat_clicked()
{
    isThisActive = false;
    ui->lineEdit_Search->setText("");
    searchKey = "";
    newChat->show();
    this->setDisabled(true);
    GetAllUsers();
}


void MainWindow::on_lineEdit_Search_textEdited(const QString &arg1)
{
    if(ui->lineEdit_Search->text().trimmed() != "")
    {
        searchKey = arg1.trimmed();
        GetAllUsers();
    }
    else if(ui->lineEdit_Search->text() == "")
    {
        searchKey = "";
        GetChats();
    }
}

