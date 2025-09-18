#include "UserState.h"

UserState::UserState(Users* user, std::string stateName) : user(user), stateName(stateName) {
    // Constructor implementation
    this->user = user;
    this->stateName = stateName;
}

std::string UserState::getStateName() const {
    return this->stateName;
}

UserState::~UserState() {
    // Destructor implementation
    if(this->user != nullptr) {
        this->user = nullptr;
    }
}

Online::Online(Users* user) : UserState(user, "Online") {
    //Online Constructor
}

Online::~Online() {
    if(this->user != nullptr) {
        this->user = nullptr;
    }
}

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

void Online::receiveMessage(Users* fromUser, std::string message, ChatRoom* room) {
    if(this->user->IsInChatRoom(room)) {
        std::cout<<this->user->getName()<<" <= "<<fromUser->getName()<<" :"<<message<<std::endl;
    }else {
        std::cout << this->user->getName() << " is not in the chat room " << std::endl;
        room->removeUser(this->user);
    }
}

void Online::log(){
    std::cout << this->user->getName() << " has gone offline "<< std::endl;
    this->user->setState(new Offline(this->user));
}

void Online::setBusy(){
    std::cout << this->user->getName() << " is now busy "<< std::endl;
    this->user->setState(new Busy(this->user));
}

Offline::Offline(Users* user) : UserState(user, "Offline") {
    //Offline Constructor
}

Offline::~Offline() {
    if(this->user != nullptr) {
        this->user = nullptr;
    }
}

void Offline::sendMessage(std::string message, ChatRoom* room) {
    std::cout << this->user->getName() << " is offline and cannot send messages." << std::endl;
}

void Offline::receiveMessage(Users* fromUser, std::string message, ChatRoom* room) {
    std::cout<< this->user->getName() << " is offline and messages will be unread." << std::endl;
    if(this->user->IsInChatRoom(room)) {
        this->user->addUnreadMessage(fromUser->getName() + " : " + message);
    }else {
        std::cout << this->user->getName() << " is not in the chat room " << std::endl;
        room->removeUser(this->user);
    }
}
void Offline::log(){
    std::cout << this->user->getName() << " has logged on "<< std::endl;
    this->user->printUnreadMessages();
    this->user->setState(new Online(this->user));
}

void Offline::setBusy(){
    std::cout << this->user->getName() << " is offline and cannot be set to busy "<< std::endl;
}

Busy::Busy(Users* user) : UserState(user, "Busy") {
    //Busy Constructor
}

Busy::~Busy() {
    if(this->user != nullptr) {
        this->user = nullptr;
    }
}

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

void Busy::receiveMessage(Users* fromUser, std::string message, ChatRoom* room) {
    std::cout<< this->user->getName() << " is busy and messages will be unread." << std::endl;
    if(this->user->IsInChatRoom(room)) {
        this->user->addUnreadMessage(fromUser->getName() + " : " + message);
    }else {
        std::cout << this->user->getName() << " is not in the chat room " << std::endl;
        room->removeUser(this->user);
    }
}

void Busy::log(){
    std::cout << this->user->getName() << " has gone offline "<< std::endl;
    this->user->setState(new Offline(this->user));
}

void Busy::setBusy(){
    std::cout << this->user->getName() << " is now not busy "<< std::endl;
    this->user->printUnreadMessages();
    this->user->setState(new Online(this->user));
}








