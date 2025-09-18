#ifndef USERSTATE_H
#define USERSTATE_H
#include <string>
#include <iostream>

class Users; // Forward declaration to avoid circular dependency
class Chatroom; // Forward declaration to avoid circular dependency
class Command; // Forward declaration to avoid circular dependency
class UserState {
    protected:
        std::string stateName;
        Users* user;
    public:
        UserState(Users* user, std::string stateName);
        std::string getStateName() const;
        virtual void sendMessage(std::string message, Chatroom room)=0; 
        virtual void receiveMessage(Users* user, std::string message, Chatroom room)=0;
        virtual void log()=0;
        virtual void setBusy()=0;
        virtual ~UserState();
};

class Online: public UserState {
    public:
        Online(Users* user);
        void sendMessage(std::string message, Chatroom room);
        void receiveMessage(Users* user, std::string message, Chatroom room);
        void log();
        void setBusy();
        ~Online() override;
};

class Offline: public UserState {
    public:
        Offline(Users* user);
        void sendMessage(std::string message, Chatroom room);
        void receiveMessage(Users* user, std::string message, Chatroom room);
        void log();
        void setBusy();
        ~Offline() override;
};

class Busy: public UserState {
    public:
        Busy(Users* user);
        void sendMessage(std::string message, Chatroom room);
        void receiveMessage(Users* user, std::string message, Chatroom room);
        void log();
        void setBusy();
        ~Busy() override;
};

#include "Users.h"
#endif

