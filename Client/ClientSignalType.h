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
    CreateNewChat
};

#endif // CLIENTSIGNALTYPE_H
