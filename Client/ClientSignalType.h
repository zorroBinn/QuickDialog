#ifndef CLIENTSIGNALTYPE_H
#define CLIENTSIGNALTYPE_H

enum class ClientSignalType
{
    UserMessage,
    Registration,
    Authentication,
    AuthDone,
    AuthError,
    GetAllUsers,
    CreateNewChat,
    GetChats
};

#endif // CLIENTSIGNALTYPE_H
