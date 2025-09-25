#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <iostream>
#include "ChatRoom.h"
class Users; // Forward declaration to avoid circular dependency

/**
 * @defgroup Command Command Pattern
 * @brief Collection of classes that belong to the Command Pattern
 * @details The classes within this group are participants of a Command design pattern.
 */

/**
 * @class Command
 * @brief Abstract base class for the Command Pattern
 * 
 * @author Byron Pillay and Kiegan Lewis
 * @date 2025-09-25
 * @ingroup Command
 */

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

/**
 * @defgroup ConcreteCommand
 * 
 * @details This group contains the Concrete Command participants of the Command Pattern.
 * **Participants:**
 * -`SendMessageCommand`: A concrete implementation of Command for handling sending messages.
 * -`LogMessageCommand`: A concrete implementation of Command for handling logging messages.
 * 
 * @ingroup Command
 * @brief Collection of Concrete Command participants
 */

/**
 * @class SendMessageCommand
 * @brief Concrete command for sending a message.
 * 
 * @author Byron Pillay and Kiegan Lewis
 * @date 2025-09-25
 * @ingroup ConcreteCommand
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
 * @ingroup ConcreteCommand
 */

class LogMessageCommand: public Command {
    public:
        LogMessageCommand(Users* fromUser, std::string message, ChatRoom* room);
        void execute();
        ~LogMessageCommand();
};


#endif