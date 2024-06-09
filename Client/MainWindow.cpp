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
    connect(this, &MainWindow::authError, authform, &Auth::authError);

    newChat = new NewChat(); //Окно создания нового чата
    connect(newChat, &NewChat::thisClosed, this, &MainWindow::newChatDestroyed);
    connect(newChat, &NewChat::createNewChat, this, &MainWindow::createNewChat);
    connect(this, &MainWindow::allUsersForNewChat, newChat, &NewChat::getUsersList);

    addUserToChat = new AddUserToChat(); //Окно добавления в групповой чат новых участников
    connect(addUserToChat, &AddUserToChat::thisClosed, this, &MainWindow::addUserToChatDestroyed);
    connect(addUserToChat, &AddUserToChat::addUser, this, &MainWindow::addUsersToChat);
    connect(this, &MainWindow::allUsersForNewParticipants, addUserToChat, &AddUserToChat::getUsersList);
    connect(this, &MainWindow::chatParticipants, addUserToChat, &AddUserToChat::getParticipantsList);

    currentChatId = -1;
    currentChatName = "";

    ui->pushButton_Chat_NewUser->setVisible(false);
}

//Деструктор
MainWindow::~MainWindow()
{
    delete ui;
    delete this->newChat;
    delete this->addUserToChat;
}

//Отправка сообщения в чате
void MainWindow::sendMessage(QString message, QString sender, int chatId)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::UserMessage << message << sender << chatId;
    socket->write(Data);
    ui->lineEdit_Mess->clear();
}

//Запрос на получение списка всех пользователей
void MainWindow::getAllUsers()
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::GetAllUsers;
    socket->write(Data);
}

//Запрос на получение списка всех чатов, в которых участвует пользователь
void MainWindow::getChats()
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
        currentChatId = -1;
        currentChatName = "";
        ui->textBrowser_CurrentChat->clear();
        ui->lineEdit_Mess->clear();
        ui->label_CurrentChatName->setText("");
        foreach (const QString &user, users) {
            if (!user.contains(searchKey, Qt::CaseInsensitive)) continue;
            QListWidgetItem *newitem = new QListWidgetItem(user);
            ui->listWidget_Chats->addItem(newitem);
        }
    }
}

//Запрос на определение типа текущего чата (личный или групповой)
void MainWindow::chatType(int chatId)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::ChatType << chatId;
    socket->write(Data);
}

//Запрос на добавление новых участников в групповой чат
void MainWindow::addUsersToChat(QStringList users, int chatId)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::AddUsersToChat << users << chatId;
    socket->write(Data);
}

//Запрос на получение истории чата
void MainWindow::getChatStory(int chatId)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << ClientSignalType::GetChatStory << chatId;
    socket->write(Data);
}

//Получение информации от сервера и типа сообщения с дальнейшим ходом действий
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
            getChats();
            break;
        }
        case ClientSignalType::AuthError:
        {
            emit authError();
            break;
        }
        case ClientSignalType::GetAllUsers:
        {
            QStringList users;
            in >> users;
            if(!isThisActive)
            {
                if(!newChat->isHidden()) emit allUsersForNewChat(users);
                else if(!addUserToChat->isHidden()) emit allUsersForNewParticipants(users);
            }
            else
            {
                showUsersInChatList(users);
            }
            break;
        }
        case ClientSignalType::GetChats:
        {
            chats.clear();
            in >> chats;
            currentChatId = -1;
            currentChatName = "";
            ui->listWidget_Chats->clear();
            ui->lineEdit_Search->clear();
            ui->lineEdit_Mess->setText("");
            ui->textBrowser_CurrentChat->clear();
            ui->pushButton_Chat_NewUser->setVisible(false);
            ui->label_CurrentChatName->setText("");
            searchKey = "";
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
                emit chatParticipants(participants, currentChatName, currentChatId);
                getAllUsers();
            }
            break;
        }
        case ClientSignalType::IsPrivateChat:
        {
            ui->pushButton_Chat_NewUser->setVisible(false);
            break;
        }
        case ClientSignalType::IsGroupChat:
        {
            ui->pushButton_Chat_NewUser->setVisible(true);
            break;
        }
        case ClientSignalType::GetChatStory:
        {
            QStringList chatStory;
            int chatId;
            in >> chatStory;
            in >> chatId;
            if(currentChatId == chatId)
            {
                ui->textBrowser_CurrentChat->clear();
                foreach (const QString &message, chatStory) {
                    ui->textBrowser_CurrentChat->append(message);
                }
                chatType(currentChatId);
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
}

//При закрытии окна добавления пользователя в чат - сделать основное окно активным
void MainWindow::addUserToChatDestroyed()
{
    this->setDisabled(false);
    isThisActive = true;
}


void MainWindow::on_pushButton_Send_clicked()
{
    if(ui->lineEdit_Mess->text().trimmed() != "") sendMessage(ui->lineEdit_Mess->text(), Username, currentChatId);
}


void MainWindow::on_lineEdit_Mess_returnPressed()
{
    if(ui->lineEdit_Mess->text().trimmed() != "") sendMessage(ui->lineEdit_Mess->text(), Username, currentChatId);
}


void MainWindow::on_pushButton_Chat_NewUser_clicked()
{
    isThisActive = false;
    addUserToChat->show();
    getChatParticipants(currentChatId);
    this->setDisabled(true);
}


void MainWindow::on_pushButton_NewChat_clicked()
{
    isThisActive = false;
    newChat->show();
    this->setDisabled(true);
    getAllUsers();
}


void MainWindow::on_lineEdit_Search_textEdited(const QString &arg1)
{
    if(ui->lineEdit_Search->text().trimmed() != "")
    {
        searchKey = arg1.trimmed();
        ui->pushButton_Chat_NewUser->setVisible(false);
        getAllUsers();
    }
    else if(ui->lineEdit_Search->text() == "")
    {
        searchKey = "";
        ui->pushButton_Chat_NewUser->setVisible(false);
        getChats();
    }
}


void MainWindow::on_listWidget_Chats_itemClicked(QListWidgetItem *item)
{
    if(ui->lineEdit_Search->text().trimmed() == "")
    {
        int currentChatIndex = ui->listWidget_Chats->currentRow(); //Индекс выбранного чата в списке
        //Получаем список всех chatId из chats
        QList<int> chatIds = chats.keys();
        if(currentChatIndex >= 0 && currentChatIndex < chatIds.size())
        {
            //Получение chatId по индексу
            currentChatId = chatIds[currentChatIndex];
            currentChatName = chats[currentChatId];
            ui->label_CurrentChatName->setText(currentChatName);
            getChatStory(currentChatId);
        }
    }
    else
    {

    }
}

