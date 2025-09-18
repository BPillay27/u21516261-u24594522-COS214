#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <iostream>
#include "ChatRoom.h"
class Users; // Forward declaration to avoid circular dependency

class Command {
    protected:
        Users* fromUser;
        std::string message;
        ChatRoom* room;
    public:
        Command(Users* fromUser, std::string message, ChatRoom* room);
        virtual void execute()=0;
        virtual ~Command();
};

class SendMessageCommand: public Command {
    public:
        SendMessageCommand(Users* fromUser, std::string message, ChatRoom* room);
        void execute();
        ~SendMessageCommand();
};

class LogMessageCommand: public Command {
    public:
        LogMessageCommand(Users* fromUser, std::string message, ChatRoom* room);
        void execute();
        ~LogMessageCommand();
};


#endif