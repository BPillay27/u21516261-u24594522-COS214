#ifndef USERS_H
#define USERS_H
#include <string>
#include <vector>
using std::vector;
#include <iostream>
#include <list>
#include "UserState.h"

class Chatroom; // Forward declaration to avoid circular dependency
class Command;  // Forward declaration to avoid circular dependency

class Users {
    protected:
        std::string name;
        vector<ChatRoom*> chatrooms;
        std::list<Command*> commandQueue;
        UserState* status;
        std::list<std::string> unreadMessages;
        void setState(UserState* state);

    public:
        Users(std::string name);
        std::string getName() const;
        void joinChatRoom(ChatRoom* chatroom);
        void leaveChatRoom(ChatRoom* chatroom);
        void send(std::string message, ChatRoom* room);
        void receive(std::string message, Users* fromUser, ChatRoom* room);
        void addCommand(Command* command);
        void executeAll();
        void log();
        void setBusy();
        std::string getState() const;
        void addUnreadMessage(const std::string& message);
        std::string UserStatus() const;
        void printUnreadMessages();
        bool IsInChatRoom(ChatRoom* room) const; 
        virtual ~Users();
};

class Byron: public Users {
    public:
        Byron();
};

class Kiegan: public Users {
    public:
        Kiegan();
};

class Bob: public Users {
    public:
        Bob();
};

#include "Command.h"
#include "ChatRoom.h"

#endif // USERS_H