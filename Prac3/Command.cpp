#include "Command.h"

/**
 * @brief This is the `Command` class constructor
 * @details This is the constructor for the `Command` class. Takes in a `User`, `string` and `ChatRoom` and sets the member variables accordingly.
 * 
 * @param fromUser The user involved in the command.
 * @param message The message being sent/logged.
 * @param room The ChatRoom in use by the command
 */

Command::Command(Users* fromUser, std::string message, ChatRoom* room){
    // Constructor implementation
    this->fromUser = fromUser;
    this->message = message;
    this->room = room;
}

/**
 * @brief Destructor for the `Command` Class
 * @details This is the destructor for the `Command` class.
 * 1. Checks if `fromUser` is `nullptr`. If not, set `fromUser` to `nullptr`.
 * 2. Checks if `room` is `nullptr`. If not, set `room` to `nullptr`.
 * 
 * @note Does not free dynamically allocated memory since it is not responsible to do so.
 */

Command::~Command(){
    // Destructor implementation
    if(this->fromUser != nullptr) {
        this->fromUser = nullptr;
    }
    if(this->room != nullptr) {
        this->room = nullptr;
    }
}

/**
 * @brief Constructor for thhe SendMessageCommand class
 * @details This is the constructor for the subclass SendMessageCommand. The function calls the base class (Command) constructor and parses the appropriate values.
 * 
 * @param fromUser The user involved in the command.
 * @param message The message being sent/logged.
 * @param room The ChatRoom in use by the command.
 */

SendMessageCommand::SendMessageCommand(Users* fromUser, std::string message, ChatRoom* room) : Command(fromUser, message, room) {
    // Constructor implementation
}

/**
 * @brief Constructor for thhe LogMessageCommand class
 * @details This is the constructor for the subclass LogMessageCommand. The function calls the base class (Command) constructor and parses the appropriate values.
 * 
 * @param fromUser The user involved in the command.
 * @param message The message being sent/logged.
 * @param room The ChatRoom in use by the command.
 */

LogMessageCommand::LogMessageCommand(Users* fromUser, std::string message, ChatRoom* room) : Command(fromUser, message, room) {
    // Constructor implementation
}

/**
 * @brief Implementation of the pure virual execute operation
 * @details 
 * 1. Checks if `fromUser` is not `nullptr`.
 * 2. Checks if 'room' is not `nullptr'.
 * 3. If all of the above is true, calls `room->sendMessage(this->message, this->fromUser)` which sends the message to the `ChatRoom`.
 */

void SendMessageCommand::execute() {
    if(this->fromUser != nullptr && this->room != nullptr) {
        this->room->sendMessage(this->message, this->fromUser);
    }
}

/**
 * @brief Implementation of the pure virual execute operation
 * @details 
 * 1. Checks if `fromUser` is not `nullptr`.
 * 2. Checks if 'room' is not `nullptr'.
 * 3. If all of the above is true, calls `room->saveMessage(this->message, this->fromUser)` which saves the message to the `ChatRoom` history.
 */

void LogMessageCommand::execute() {
    if(this->fromUser != nullptr && this->room != nullptr) {
        this->room->saveMessage(this->message, this->fromUser);
    }
}

/**
 * @brief Destructor for the SendMessageCommand class
 */

SendMessageCommand::~SendMessageCommand() {
    // Destructor implementation
}

/**
 * @brief Destructor for the LogMessageCommand class
 */

LogMessageCommand::~LogMessageCommand() {
    // Destructor implementation
}


