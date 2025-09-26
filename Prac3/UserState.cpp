#include "UserState.h"

/**
 * @brief Constructor for the `UserState` class.
 * 
 * @param user The user.
 * @param stateName The state of the user.
 */

UserState::UserState(Users* user, std::string stateName) : user(user), stateName(stateName) {
    // Constructor implementation
    this->user = user;
    this->stateName = stateName;
}

/**
 * @brief Getter method for the state.
 * @returns This function returns the state of the user.
 */

std::string UserState::getStateName() const {
    return this->stateName;
}

/**
 * @brief destructor for the `UserState` class.
 * @note Does not delete the allocated memory.
 */

UserState::~UserState() {
    // Destructor implementation
    if(this->user != nullptr) {
        this->user = nullptr;
    }
}

/**
 * @brief Conctructor for the `Online` state.
 * @param user The user who's state will be set to `Online`.
 */

Online::Online(Users* user) : UserState(user, "Online") {
    //Online Constructor
}

/**
 * @brief Destructor for the `Online` class.
 * @note Does not delete the allocated memory.
 */

Online::~Online() {
    if(this->user != nullptr) {
        this->user = nullptr;
    }
}

/**
 * @brief Method for an `Online` `User` to send a message.
 * 
 * @details
 * 1. Checks if the `User` is a member of the `ChatRoom`. If not, return.
 * 2. Creates a `SendMessageCommand`.
 * 3. Creates a `LogMessageCommand`.
 * 4. Adds the Commands to the `CommandQueue` and calls `execute()`.
 * 
 * @param message The message sent by the `User`.
 * @param room The `ChatRoom` to receive the `message`.
 */

void Online::sendMessage(std::string message, ChatRoom* room) {
    if(!this->user->IsInChatRoom(room)) {
        std::cout << this->user->getName() << " is not in the chat room " << std::endl;
        return;
    }
    Command* command = new SendMessageCommand(this->user, message, room);
    Command* logCommand = new LogMessageCommand(this->user, message, room);
    this->user->addCommand(command);
    this->user->addCommand(logCommand);
    this->user->executeAll();
}

/**
 * @brief Method for an `Online` user to receive a message.
 * 
 * @param fromUser The `User` who sent the `message`.
 * @param message The `message` sent by the `User`.
 * @param room The `ChatRoom` which contains the `fromUser` and the current `User`.
 */

void Online::receiveMessage(Users* fromUser, std::string message, ChatRoom* room) {
    if(this->user->IsInChatRoom(room)) {
        std::cout<<this->user->getName()<<" <= "<<fromUser->getName()<<" :"<<message<<std::endl;
    }else {
        std::cout << this->user->getName() << " is not in the chat room " << std::endl;
        room->removeUser(this->user);
    }
}

/**
 * @brief Method to for an Online User to log off.
 */

void Online::log(){
    std::cout << this->user->getName() << " has gone offline "<< std::endl;
    this->user->setState(new Offline(this->user));
}

/**
 * @brief Method to set the users state to `Busy`.
 */

void Online::setBusy(){
    std::cout << this->user->getName() << " is now busy "<< std::endl;
    this->user->setState(new Busy(this->user));
}

/**
 * @brief Constructor for the Offline state.
 */

Offline::Offline(Users* user) : UserState(user, "Offline") {
    //Offline Constructor
}

/**
 * @brief Destructor for the Offline class
 * @note Does not free dynamic memory.
 */

Offline::~Offline() {
    if(this->user != nullptr) {
        this->user = nullptr;
    }
}

/**
 * @brief Method for the `Offline` class to handle sending messages.
 * @note An Offline user cannot send messages.
 * @param message The `message` the user is sending.
 * @param room The `ChatRoom` the user is sending the `message` to.
 */

void Offline::sendMessage(std::string message, ChatRoom* room) {
    std::cout << this->user->getName() << " is offline and cannot send messages." << std::endl;
}

/**
 * @brief Method for an Offline User to handle receiving messages.
 * @details Checks if this user is a member of the room, if yes adds the message to the `unreadMessages`.
 * 
 * @param fromUser The user which sent the message.
 * @param message The message sent by `fromUser`.
 * @param room The `ChatRoom` which both fromUser and the currentUser is a member of.
 */

void Offline::receiveMessage(Users* fromUser, std::string message, ChatRoom* room) {
    std::cout<< this->user->getName() << " is offline and messages will be unread." << std::endl;
    if(this->user->IsInChatRoom(room)) {
        this->user->addUnreadMessage(fromUser->getName() + " : " + message);
    }else {
        std::cout << this->user->getName() << " is not in the chat room " << std::endl;
        room->removeUser(this->user);
    }
}

/**
 * @brief Method for an Offline user to login
 */
void Offline::log(){
    std::cout << this->user->getName() << " has logged on "<< std::endl;
    this->user->printUnreadMessages();
    this->user->setState(new Online(this->user));
}

/**
 * @brief Method for an Offline user to set state to `Busy`.
 * @note An Offline user cannot be `Busy`. This method just prints a message to console and returns.
 */

void Offline::setBusy(){
    std::cout << this->user->getName() << " is offline and cannot be set to busy "<< std::endl;
}

/**
 * @brief Constructor for the `Busy` class
 * @param user The user who's state will be set to `Busy`.
 */

Busy::Busy(Users* user) : UserState(user, "Busy") {
    //Busy Constructor
}

/**
 * @brief Destructor for the Busy class
 * @note Does not free any dynamically allocated memory.
 */

Busy::~Busy() {
    if(this->user != nullptr) {
        this->user = nullptr;
    }
}

/**
 * @brief Method for a Busy user to send a message.
 * 
 * @param message The message sent by the user.
 * @param room The `ChatRoom` to receive the message if the user is a member of the `ChatRoom`.
 */

void Busy::sendMessage(std::string message, ChatRoom* room) {
    if(!this->user->IsInChatRoom(room)) {
        std::cout << this->user->getName() << " is not in the chat room " << std::endl;
        return;
    }
    Command* command = new SendMessageCommand(this->user, message, room);
    Command* logCommand = new LogMessageCommand(this->user, message, room);
    this->user->addCommand(command);
    this->user->addCommand(logCommand);
    this->user->executeAll();
}

/**
 * @brief Methof for a `Busy` user to receive a message. The message is places in `unreadMessages`.
 * 
 * @param fromUser The user which sent the message.
 * @param message The string sent by `fromUser`.
 * @param room The `ChatRoom` which fromUser and user must be a memeber of.
 */

void Busy::receiveMessage(Users* fromUser, std::string message, ChatRoom* room) {
    std::cout<< this->user->getName() << " is busy and messages will be unread." << std::endl;
    if(this->user->IsInChatRoom(room)) {
        this->user->addUnreadMessage(fromUser->getName() + " : " + message);
    }else {
        std::cout << this->user->getName() << " is not in the chat room " << std::endl;
        room->removeUser(this->user);
    }
}

/**
 * @brief Method for a Busy user to log off.
 */

void Busy::log(){
    std::cout << this->user->getName() << " has gone offline "<< std::endl;
    this->user->setState(new Offline(this->user));
}

/**
 * @brief Method for a `Busy` User to set their status off `Busy`.
 */

void Busy::setBusy(){
    std::cout << this->user->getName() << " is now not busy "<< std::endl;
    this->user->printUnreadMessages();
    this->user->setState(new Online(this->user));
}








