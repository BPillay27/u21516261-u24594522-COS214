#ifndef USERSTATE_H
#define USERSTATE_H
#include <string>
#include <iostream>

class Users; // Forward declaration to avoid circular dependency
class ChatRoom; // Forward declaration to avoid circular dependency
class Command; // Forward declaration to avoid circular dependency

/**
 * @defgroup State_Pattern
 * @brief Collection of classes that participate in a State Design Pattern
 */

/**
 * @defgroup States
 * @brief Collection of Abtract state classes.
 * @ingroup State_Pattern
 */

/**
 * @defgroup Concrete_States
 * @brief Collection of Concrete States which inherit from a State.
 * @ingroup State_Pattern
 */

/**
 * @class UserState
 * @brief This is the Abstract state class from which Concrete states will be derived.
 * @ingroup States
 */

class UserState {
    
    protected:
        std::string stateName;
        Users* user;
    public:
        UserState(Users* user, std::string stateName);
        std::string getStateName() const;
        virtual void sendMessage(std::string message, ChatRoom* room)=0; 
        virtual void receiveMessage(Users* user, std::string message, ChatRoom* room)=0;
        virtual void log()=0;
        virtual void setBusy()=0;
        virtual ~UserState();
};

/**
 * @class Online
 * @brief Class to represent when a `User` is online.
 * @ingroup Concrete_States
 */

class Online: public UserState {
    public:
        Online(Users* user);
        void sendMessage(std::string message, ChatRoom* room);
        void receiveMessage(Users* user, std::string message, ChatRoom* room);
        void log();
        void setBusy();
        ~Online();
};

/**
 * @class Offline
 * @brief Class to represent when a `User` is offline.
 * @ingroup Concrete_States
 */

class Offline: public UserState {
    public:
        Offline(Users* user);
        void sendMessage(std::string message, ChatRoom* room);
        void receiveMessage(Users* user, std::string message, ChatRoom* room);
        void log();
        void setBusy();
        ~Offline();
};

/**
 * @class Busy
 * @brief Class to represent when a `User` is busy.
 * @ingroup Concrete_States
 */

class Busy: public UserState {
    public:
        Busy(Users* user);
        void sendMessage(std::string message, ChatRoom* room);
        void receiveMessage(Users* user, std::string message, ChatRoom* room);
        void log();
        void setBusy();
        ~Busy();
};

#include "Command.h"
#include "Users.h"
#endif

