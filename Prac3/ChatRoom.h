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
    //friend class UserIterator; if there are issues with visibility, uncomment this line
    private:
        std::string ChatHistory;
        std::list<Users*> users;
    protected:
        UserIterator createIterator(); //Accessing private member function so should be protected otherwise you could access users as if it were public
    public:
        ChatRoom();
        virtual void registerUser(Users *user)=0;
        void sendMessage(std::string message, Users *fromUser);
        void saveMessage(std::string message, Users *fromUser);
        virtual void removeUser(Users *user)=0;
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

class ParrotSort:public ChatRoom{ // extra room for fun 
    public:
        ParrotSort();
        void registerUser(Users *user) override;
        void removeUser(Users *user) override;
};

#include "Iterator.h"

#endif // CHATROOM_H
