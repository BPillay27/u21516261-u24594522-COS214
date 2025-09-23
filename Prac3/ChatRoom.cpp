#include "ChatRoom.h"

ChatRoom::ChatRoom(){
    // Constructor implementation
}

ChatRoom::~ChatRoom(){
    delete chatHistory;
    chatHistory = nullptr;
    delete users;
    users = nullptr;
}

void ChatRoom::sendMessage(std::string message, Users* fromUser){
    //Need to implement
}

void ChatRoom::saveMessage(std::string message, Users* fromUser){
    //Need to implement
}

void ChatRoom::displayChatHistory(){
    ChatHistoryIterator* chatIt= dynamic_cast<ChatHistoryIterator*>(chatHistory->createIterator());
    while(!chatIt->isDone()) {
        std::cout <<chatIt->currentItem() << std::endl;
        chatIt->next();
    }
    delete chatIt;
}

CtrlCat::CtrlCat():ChatRoom(){
    //CtrlCat Constructor
    this->chatHistory=new ChatHistory();
    this->users=new UserList();
}

void CtrlCat::registerUser(Users* user){
    //to be implemented
    this->chatHistory->add(user->getName() + " has joined the CtrlCat room.");
    this->users->addUser(user);
    //Like this for the others but replace joined with left
}

void CtrlCat::removeUser(Users *user){
    //to be implemented
}

void Dogorithm::registerUser(Users *user){
    //to be implemented
}

Dogorithm::Dogorithm():ChatRoom(){
    //Dogorithm Constructor
    this->chatHistory=new ChatHistory();
    this->users=new UserList();
}

void Dogorithm::removeUser(Users *user){
    //to be implemented
}
Dogorithm::~Dogorithm(){
    //Dogorithm Destructor

}

CtrlCat::~CtrlCat(){
    //CtrlCat Destructor

}

