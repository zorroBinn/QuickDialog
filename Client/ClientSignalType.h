#ifndef CLIENTSIGNALTYPE_H
#define CLIENTSIGNALTYPE_H

enum class ClientSignalType
{
    UserMessage,
    Registration,
    Authentication,
    AuthDone,
    AuthError
};

#endif // CLIENTSIGNALTYPE_H
