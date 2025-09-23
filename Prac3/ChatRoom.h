#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include "Users.h"
#include <list>
#include <iostream>
#include "Container.h"
class Users;
class ChatHistory;
class UserList;
class UserIterator;

class ChatRoom {
    //friend class UserIterator; if there are issues with visibility, uncomment this line
    protected:
        ChatHistory* chatHistory;
        UserList* users;
    public:
        ChatRoom();
        virtual void registerUser(Users* user)=0;
        void sendMessage(std::string message, Users* fromUser);
        void saveMessage(std::string message, Users* fromUser);
        void displayChatHistory();
        virtual void removeUser(Users* user)=0;
        virtual ~ChatRoom();
};

class CtrlCat:public ChatRoom{
    public:
        CtrlCat();
        void registerUser(Users* user) override;
        void removeUser(Users* user) override;
        ~CtrlCat();
};

class Dogorithm:public ChatRoom{
    public:
        Dogorithm();
        void registerUser(Users* user) override;
        void removeUser(Users* user) override;
        ~Dogorithm();
};



#include "Iterator.h"

#endif // CHATROOM_H
