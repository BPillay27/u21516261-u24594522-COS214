#include "Iterator.h"

UserIterator::UserIterator(std::list<Users*>* list) {
    // Constructor implementation
    this->users = list;
    this->start = list->begin();
    this->end = list->end();
    this->current = start;
}

Users* UserIterator::first(){
    return *this->start;
}

Users* UserIterator::next(){
    if(this->current != this->end) {
        ++this->current;
    }
    if(this->current != this->end) {
        return *this->current;
    } else {
        return nullptr;
    }
}

bool UserIterator::isDone(){
    return this->current == this->end;
}
Users* UserIterator::currentItem(){
    if(this->current != this->end) {
        return *this->current;
    } else {
        return nullptr; 
    }
}

void UserIterator::remove(){
    if(this->current != this->end) {
        this->current = this->users->erase(this->current);
    }
}

UserIterator::~UserIterator() {
    users = nullptr;
}

ChatHistoryIterator::ChatHistoryIterator(std::vector<std::string>* history) {
    this->history = history;
    this->current = 0;
}

std::string ChatHistoryIterator::first(){
    if(this->history->empty()) {
        return "";
    }
    return (*this->history)[0];
}

std::string ChatHistoryIterator::next(){
    ++this->current;
    if(this->current < this->history->size()) {
        return (*this->history)[this->current];
    } else {
        return "";
    }
}

bool ChatHistoryIterator::isDone(){
    return this->current >= this->history->size();
}

void ChatHistoryIterator::remove(){
    if(this->current < this->history->size()) {
        this->history->erase(this->history->begin() + this->current);
        if(this->current >= this->history->size() && this->current > 0) {
            --this->current;
        }
    }
}

std::string ChatHistoryIterator::currentItem(){
    if(this->current < this->history->size()) {
        return (*this->history)[this->current];
    } else {
        return "";
    }
}

ChatHistoryIterator::~ChatHistoryIterator() {
    history = nullptr;
}
