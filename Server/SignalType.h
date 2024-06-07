#ifndef SIGNALTYPE_H
#define SIGNALTYPE_H

enum class SignalType
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

#endif // SIGNALTYPE_H
