#include "Users.h"

/**
 * @brief Constructor for the `Users` class.
 * @details 
 * 1. Sets the `name` member variable to the `name` parameter.
 * 2. Inialises `status` to online.
 * 3. Clears `unreadMessages`, `chatrooms` and `commandQueue`.
 * @param name The name of the `User`
 */

Users::Users(std::string name){
    this->name=name;
    this->status=new Online(this);
    this->unreadMessages.clear();
    this->chatrooms.clear();
    this->commandQueue.clear();
}

/**
 * @brief Constructor for the `Byron` class.
 * @details Calls the base class, `Users`, constructor with the value "Byron".
 */

Byron::Byron():Users("Byron"){
    //Byron Constructor
}

/**
 * @brief Constructor for the `Kiegan` class.
 * @details Calls the base class, `Users`, constructor with the value "Kiegan".
 */

Kiegan::Kiegan():Users("Kiegan"){
    //Kiegan Constructor
}

/**
 * @brief Constructor for the `Bob` class.
 * @details Calls the base class, `Users`, constructor with the value "Bob".
 */

Bob::Bob():Users("Bob"){
    //Bob Constructor
}

/**
 * @brief Destructor for the abstract Users class
 * @details
 * 1. Checks if `status` is not `nullptr`. If true, deletes `status` and sets it to `nullptr`.
 * 2. Sets each item in `chatrooms` to `nullptr`.
 * 3. Clears `chatrooms`, calls `executeAll()` and clears the `commandQueue`.
 * 3. Clears each message in `unreadMessages`.
 */

Users::~Users(){
    //Need to implement destructor
    if(this->status!=nullptr){
        delete this->status;
        this->status=nullptr;
    }
    for(auto chatroom : this->chatrooms){
        chatroom=nullptr;
    }
    this->chatrooms.clear();
    executeAll();
    this->commandQueue.clear();
    for(auto message : this->unreadMessages){
        message.clear();
    }
    this->unreadMessages.clear();
}

/**
 * @brief Method to set the state of `User`
 * 
 * @param state The `state` you which to change this `User`'s `state` to.
 * @note This function does nothing if the provided `state` is `nullptr`.
 */

void Users::setState(UserState* state){
    if(state==nullptr){
        return;
    }

    if(this->status!=nullptr){
        UserState* holder=this->status;
        this->status=nullptr;
        delete holder;
    }
    this->status=state;
}

/**
 * @brief Getter method for the `Users` name.
 */

std::string Users::getName(){
    return this->name;
}

/**
 * @brief Getter method for the `Users` state.
 */

std::string Users::getState() const{
    return this->status->getStateName();
}

/**
 * @brief Method for a `User` to join a `Chatroom`
 * @details
 * 1. Checks if the `User` is already in the `chatroom` and returns if true.
 * 2. Pushes the `chatroom` into the `Users` list of `ChatRoom`.
 * 3. Calls `chatroom->registerUser(this)` to register this `Users` to the `ChatRoom` list of `Users`.
 * @param chatroom The `ChatRoom` the `User` will join.
 * @note This function does nothe if nullptr is `parsed` to it.
 */

void Users::joinChatRoom(ChatRoom* chatroom){
    if(chatroom==nullptr){
        return;
    }
    for(auto room : this->chatrooms){
        if(room==chatroom){
            std::cout<<this->name<<" is already in the chat room "<<std::endl;
            return;
        }
    }
    this->chatrooms.push_back(chatroom);
    chatroom->registerUser(this);
}

/**
 * @brief Method for the `Users` to leave the `chatroom`.
 * @details The `User` goes through `chatroom` and looks for itself. If found, removes itself from the list. If the `User` is not in the list, prints a message to the console and returns.
 * @param chatroom The `ChatRoom` to find and remove the `Users` from.
 */

void Users::leaveChatRoom(ChatRoom* chatroom){
    if(chatroom==nullptr){
        return;
    }
    for(auto it=this->chatrooms.begin(); it!=this->chatrooms.end(); ++it){
        if(*it==chatroom){
            this->chatrooms.erase(it);
            chatroom->removeUser(this);
            return;
        }
    }
    std::cout<<this->name<<" is not in the chat room "<<std::endl;
}

/**
 * @brief Method for the `User` to send a message to a `ChatRoom`.
 * @details Calls `status->sendMessage(message, room)`.
 * @param message The string the `User` is sending to the chat
 * @param room The `ChatRoom` the `message` will be sent to.
 */

void Users::send(std::string message, ChatRoom* room){
    if(room==nullptr){
        return;
    }
    this->status->sendMessage(message, room);
}

/**
 * @details Method to receive a `message` from another `User` in the `Chatroom`.
 * 
 * @param message The `message` sent to the `ChatRoom`.
 * @param fromUser The `User` that sent the `message`.
 * @param room The `ChatRoom` which both this `User` and the `fromUser` is a member of.
 */

void Users::receive(std::string message, Users* fromUser, ChatRoom* room){
    if(room==nullptr || fromUser==nullptr){
        return;
    }
    this->status->receiveMessage(fromUser, message, room);
}

/**
 * @brief Method to add a `Command` to the `CommandQueue`.
 * @param command The `Command` to be added to the `CommandQueue`.
 */

void Users::addCommand(Command* command){
    if(command==nullptr){
        return;
    }
    this->commandQueue.push_back(command);
}

/**
 * @brief Method to check if this `User` is a member of a `ChatRoom`.
 * @param room The `ChatRoom`in which to search for the user.
 * @return This function returns true if this `User` is a member of the `room`. Otherwise, returns false.
 */

bool Users::IsInChatRoom(ChatRoom* room) const {
    for(auto chat : this->chatrooms) {
        if(chat == room) {
            return true;
        }
    }
    return false;
}

/**
 * @brief This method executes all commands in the CommandQueue.
 */

void Users::executeAll(){
    for(auto command : this->commandQueue){
        command->execute();
        delete command;
    }
    this->commandQueue.clear();
}

/**
 * @brief Method to login or logout.
 */

void Users::log(){
    this->status->log();
}

/**
 * @brief Method to set `status` to busy.
 */
void Users::setBusy(){
    this->status->setBusy();
}

/**
 * @brief Method to add an unread message to a list.
 * @param message The message to add to the unread messages.
 */
void Users::addUnreadMessage(const std::string& message) {
    this->unreadMessages.push_back(message);
}

/**
 * @brief Method to get a string with the `Users` status.
 * @returns A string which contains the `Users` current status.
 */

std::string Users::UserStatus() const {
    return this->name + " is currently " + this->status->getStateName();
}

/**
 * @brief Method to print all unread messages to console.
 */

void Users::printUnreadMessages() {
    if(this->unreadMessages.empty()) {
        std::cout << this->name << " has no unread messages." << std::endl;
        return;
    }
    std::cout << this->name << "'s unread messages:" << std::endl;
    for(const auto& msg : this->unreadMessages) {
        std::cout << msg << std::endl;
    }
    this->unreadMessages.clear();
}


