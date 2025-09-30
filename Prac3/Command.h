#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <iostream>
#include "ChatRoom.h"
class Users; // Forward declaration to avoid circular dependency

/**
 * @defgroup Command_Pattern
 * @brief This is a collection of classes that participate in the Command Design Pattern.
 */

/**
 * @defgroup Commands
 * @brief Collection of abstract classes that belong to the Command Pattern
 * @details The classes within this group are participants of a Command design pattern.
 * @ingroup Command_Pattern
 */

/**
 * @class Command
 * @brief Abstract base class for the Command Pattern
 * 
 * @author Byron Pillay and Kiegan Lewis
 * @date 2025-09-25
 * @ingroup Commands
 */

class Command {
    protected:
        /**
         * @brief The `User` which sent the message.
         */
        Users* fromUser;
        /**
         * @brief The `message` string sent by `fromUser`.
         */    
        std::string message;
        /**
         * @brief The `ChatRoom` which `fromUser` sent the `message` to.
         */
        ChatRoom* room;
    public:
        Command(Users* fromUser, std::string message, ChatRoom* room);
        virtual void execute()=0;
        virtual ~Command();
};

/**
 * @defgroup Concrete_Commands
 * 
 * @details This group contains the Concrete Command participants of the Command Pattern.
 * **Participants:**
 * -`SendMessageCommand`: A concrete implementation of Command for handling sending messages.
 * -`LogMessageCommand`: A concrete implementation of Command for handling logging messages.
 * 
 * @ingroup Command_Pattern
 * @brief Collection of Concrete Command participants
 */

/**
 * @class SendMessageCommand
 * @brief Concrete command for sending a message.
 * 
 * @author Byron Pillay and Kiegan Lewis
 * @date 2025-09-25
 * @ingroup Concrete_Commands
 */

class SendMessageCommand: public Command {
    public:
        SendMessageCommand(Users* fromUser, std::string message, ChatRoom* room);
        void execute();
        ~SendMessageCommand();
};

/**
 * @class LogMessageCommand
 * @brief Concrete command for logging a message.
 * 
 * @author Byron Pillay and Kiegan Lewis
 * @date 2025-09-25
 * @ingroup Concrete_Commands
 */

class LogMessageCommand: public Command {
    public:
        LogMessageCommand(Users* fromUser, std::string message, ChatRoom* room);
        void execute();
        ~LogMessageCommand();
};


#endif