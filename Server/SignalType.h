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
    CreateNewChat
};

#endif // SIGNALTYPE_H
