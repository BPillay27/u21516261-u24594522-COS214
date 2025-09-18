#include "Command.h"

Command::Command(Users* fromUser, std::string message, ChatRoom* room){
    // Constructor implementation
    this->fromUser = fromUser;
    this->message = message;
    this->room = room;
}

Command::~Command(){
    // Destructor implementation
    if(this->fromUser != nullptr) {
        this->fromUser = nullptr;
    }
    if(this->room != nullptr) {
        this->room = nullptr;
    }
}

SendMessageCommand::SendMessageCommand(Users* fromUser, std::string message, ChatRoom* room) : Command(fromUser, message, room) {
    // Constructor implementation
}

LogMessageCommand::LogMessageCommand(Users* fromUser, std::string message, ChatRoom* room) : Command(fromUser, message, room) {
    // Constructor implementation
}

void SendMessageCommand::execute() {
    if(this->fromUser != nullptr && this->room != nullptr) {
        this->room->sendMessage(this->message, this->fromUser);
    }
}

void LogMessageCommand::execute() {
    if(this->fromUser != nullptr && this->room != nullptr) {
        this->room->saveMessage(this->message, this->fromUser);
    }
}

SendMessageCommand::~SendMessageCommand() {
    // Destructor implementation
}

LogMessageCommand::~LogMessageCommand() {
    // Destructor implementation
}


