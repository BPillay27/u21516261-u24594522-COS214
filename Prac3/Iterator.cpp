#include "Iterator.h"

Iterator::~Iterator() {
    // Destructor implementation
    //Nothing
}

UserIterator::UserIterator(std::list<Users*>* list) {
    // Constructor implementation
    this->users = list;
    this->start = list->begin();
    this->end = list->end();
    this->current = start;
}

Users* UserIterator::first(){
    // Return the first element
    return *this->start;
}
Users* UserIterator::next(){
    // Move to the next element and return it
    if(this->current != this->end) {
        ++this->current;
    }
    if(this->current != this->end) {
        return *this->current;
    } else {
        return nullptr; // or handle end of iteration as needed
    }
}

bool UserIterator::isDone(){
    // Check if the iteration is complete
    return this->current == this->end;
}
Users* UserIterator::currentItem(){
    // Return the current element
    if(this->current != this->end) {
        return *this->current;
    } else {
        return nullptr; // or handle end of iteration as needed
    }
}

void UserIterator::remove(){
    // Remove the current element
    if(this->current != this->end) {
        this->current = this->users->erase(this->current);
    }
}

UserIterator::~UserIterator() {
    // Destructor implementation
    users = nullptr;
}