#include "Users.h"

Users::Users(std::string name){
    this->name=name;
    this->status=new Online(this);
    this->unreadMessages.clear();
    this->chatrooms.clear();
    this->commandQueue.clear();
}

Byron::Byron():Users("Byron"){
    //Byron Constructor
}

Kiegan::Kiegan():Users("Kiegan"){
    //Kiegan Constructor
}

Bob::Bob():Users("Bob"){
    //Bob Constructor
}

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

std::string Users::getName() const{
    return this->name;
}

std::string Users::getState() const{
    return this->status->getStateName();
}

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

void Users::send(std::string message, ChatRoom* room){
    if(room==nullptr){
        return;
    }
    this->status->sendMessage(message, room);
}

void Users::receive(std::string message, Users* fromUser, ChatRoom* room){
    if(room==nullptr || fromUser==nullptr){
        return;
    }
    this->status->receiveMessage(fromUser, message, room);
}

void Users::addCommand(Command* command){
    if(command==nullptr){
        return;
    }
    this->commandQueue.push_back(command);
}

bool Users::IsInChatRoom(ChatRoom* room) const {
    for(auto chat : this->chatrooms) {
        if(chat == room) {
            return true;
        }
    }
    return false;
}

void Users::executeAll(){
    for(auto command : this->commandQueue){
        command->execute();
        delete command;
    }
    this->commandQueue.clear();
}

void Users::log(){
    this->status->log();
}

void Users::setBusy(){
    this->status->setBusy();
}

void Users::addUnreadMessage(const std::string& message) {
    this->unreadMessages.push_back(message);
}

std::string Users::UserStatus() const {
    return this->name + " is currently " + this->status->getStateName();
}

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


