#ifndef SIGNALTYPE_H
#define SIGNALTYPE_H

enum class SignalType
{
    UserMessage,
    Registration,
    Authentication,
    AuthDone,
    AuthError,
    GetAllUsers
};

#endif // SIGNALTYPE_H
