#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include "Users.h"
#include <list>
#include <iostream>
#include "Iterator.h"
class Users;
class UserIterator;

class ChatRoom {
    private:
        std::string ChatHistory;
        std::list<Users*> users;
    public:
        ChatRoom();
        virtual void registerUser(Users *user)=0;
        void sendMessage(std::string message, Users *fromUser);
        void saveMessage(std::string message, Users *fromUser);
        virtual void removeUser(Users *user)=0;
        UserIterator createIterator();
};

class CtrlCat:public ChatRoom{
    public:
        CtrlCat();
        void registerUser(Users *user) override;
        void removeUser(Users *user) override;
};

class Dogorithm:public ChatRoom{
    public:
        Dogorithm();
        void registerUser(Users *user) override;
        void removeUser(Users *user) override;
};

class ParrotSort:public ChatRoom{
    public:
        ParrotSort();
        void registerUser(Users *user) override;
        void removeUser(Users *user) override;
};

#endif // CHATROOM_H
