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

/**
 * @defgroup Colleagues
 * @brief Collection of classes that particpate in the Mediator Pattern as a Colleague
 * @ingroup Mediator_Pattern
 */

/**
 * @defgroup Concrete_Colleagues
 * @brief Collection of conrete implementations of a Colleague.
 * @ingroup Mediator_Pattern
 */


/**
 * @class Users
 * @brief This is a User who uses multiple `ChatRooms`.
 * @ingroup Colleagues
 */
class Users {
    protected:
        std::string name;
        vector<ChatRoom*> chatrooms;
        std::list<Command*> commandQueue;
        UserState* status;
        std::list<std::string> unreadMessages;

    public:
        void setState(UserState* state);
        Users(std::string name);
        std::string getName();
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

/**
 * @class Byron
 * @brief Concrete implementation of Users
 * @ingroup Concrete_Colleagues
 */

class Byron: public Users {
    public:
        Byron();
};

/**
 * @class Kiegan
 * @brief Concrete implementation of Users
 * @ingroup Concrete_Colleagues
 */

class Kiegan: public Users {
    public:
        Kiegan();
};

/**
 * @class Bob
 * @brief Concrete implementation of Users
 * @ingroup Concrete_Colleagues
 */

class Bob: public Users {
    public:
        Bob();
};

#include "Command.h"
#include "ChatRoom.h"

#endif // USERS_H