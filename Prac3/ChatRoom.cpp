#include "ChatRoom.h"

ChatRoom::ChatRoom(){
    // Constructor implementation
}

void ChatRoom::sendMessage(std::string message, Users *fromUser){
    //Need to implement
}

void ChatRoom::saveMessage(std::string message, Users *fromUser){
    //Need to implement
}

UserIterator ChatRoom::createIterator(){
    return UserIterator(&this->users);
}

CtrlCat::CtrlCat():ChatRoom(){
    //CtrlCat Constructor
}

void CtrlCat::registerUser(Users *user){
    //to be implemented
}

void CtrlCat::removeUser(Users *user){
    //to be implemented
}

void Dogorithm::registerUser(Users *user){
    //to be implemented
}

Dogorithm::Dogorithm():ChatRoom(){
    //Dogorithm Constructor
}

void Dogorithm::removeUser(Users *user){
    //to be implemented
}

ParrotSort::ParrotSort():ChatRoom(){
    //ParrotSort Constructor
}

void ParrotSort::registerUser(Users *user){
    //to be implemented
}

void ParrotSort::removeUser(Users *user){
    //to be implemented
}


