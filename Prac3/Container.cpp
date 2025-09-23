#include "Container.h"

UserList::UserList() {
    // Constructor implementation
    this->users=std::list<Users*>();
}

void UserList::addUser(Users* user) {
    if(user==nullptr){
        return;
    }
    UserIterator* it = dynamic_cast<UserIterator*>(this->createIterator());
    while(!it->isDone()) {
        if(it->currentItem() == user) {
            delete it;
            return;
        }
        it->next();
    }
    delete it; // Clean up iterator
    this->users.push_back(user);
}

void UserList::removeUser(Users* user) {
    if(user==nullptr){
        return;
    }
    UserIterator* it = dynamic_cast<UserIterator*>(this->createIterator());
    while(!it->isDone()) {
        if(it->currentItem() == user) {
            it->remove();
            delete it; // Clean up iterator
            return; // User found and removed
        }
        it->next();
    }
    delete it; // Clean up iterator
}

Iterator* UserList::createIterator() {
    return new UserIterator(&this->users);
}

UserList::~UserList() {
    // Destructor implementation
    for(auto user : this->users) {
        user = nullptr;
    }
    this->users.clear();
}

ChatHistory::ChatHistory() {
    // Constructor implementation
    this->history=std::vector<std::string>();
}

void ChatHistory::add(const std::string message) {
    this->history.push_back(message);
}

Iterator* ChatHistory::createIterator() {
    return new ChatHistoryIterator(&this->history);
}

ChatHistory::~ChatHistory() {
    // Destructor implementation
    this->history.clear();
}

void ChatHistory::remove(const std::string& message) {
    ChatHistoryIterator* chatIT = dynamic_cast<ChatHistoryIterator*>(this->createIterator());
    while(!chatIT->isDone()) {
        if(chatIT->currentItem() == message) {
            chatIT->remove();
            delete chatIT;
            return;
        }
        chatIT->next();
    }
    delete chatIT;
    
}
