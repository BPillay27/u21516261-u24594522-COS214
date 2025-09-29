#include "Iterator.h"

/**
 * @brief Constructor for the `UserIterator` class.
 * @details This is the constructor for the `UserIterator` class. 
 * 1. It takes a list of `User` objects and sets `users` to this list.
 * 2. It sets `start` to `list->begin()`.
 * 3. It sets `end` to `list->end()`.
 * 4. It sets `current` to `start`.
 * 
 * @param list This is a list of `User` objects.
 */

UserIterator::UserIterator(std::list<Users*>* list) {
    // Constructor implementation
    this->users = list;
    this->start = list->begin();
    this->end = list->end();
    this->current = start;
}

/**
 * @brief Getter method for `start`.
 * @details This method returns the 1st `Users` in the list.
 * 
 * @returns A reference to the 1st element in the list.
 */

Users* UserIterator::first(){
    return *this->start;
}

/**
 * @brief Method to step through the list of `Users`.
 * @details This is a method to step through the list of `Users`.
 * 1. Checks if the current `Users` object is not the end of the list. If true, moves current to the next object in the list.
 * 2. Checks if `current` is not `end`. If true, returns `current`. If false, returns `nullptr`.
 * 
 * @returns If, post increment, the object does not equal `end` then the function returns `*this->current`. Otherwise, returns `nullptr`.
 */

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

/**
 * @brief Determines if the end of the list is reached.
 * @returns Function returns `true` if current=end. Otherwise, returns `false`.
 */

bool UserIterator::isDone(){
    return this->current == this->end;
}

/**
 * @brief Getter for `current`
 * @returns This function returns `current` if `current` is not the `end`. Otherwise, returns `nullptr`.
 */

Users* UserIterator::currentItem(){
    if(this->current != this->end) {
        return *this->current;
    } else {
        return nullptr; 
    }
}

/**
 * @brief Method to remove a `Users` object from the list.
 */

void UserIterator::remove(){
    if(this->current != this->end) {
        this->current = this->users->erase(this->current);
    }
}

/**
 * @brief Destructor for the `UserIterator` class.
 */

UserIterator::~UserIterator() {
    users = nullptr;
}

/**
 * @brief Constructor for the `ChatHistoryIterator` class.
 * @details Sets the `history` member variable to the parameter `history`, and sets `current` to 0.
 * 
 * @param history A vector of strings, typically the messages of the a `ChatRoom`.
 */

ChatHistoryIterator::ChatHistoryIterator(std::vector<std::string>* history) {
    this->history = history;
    this->current = 0;
}

/**
 * @brief Method to get the first string in the vector.
 * @details
 * 1. Checks if the vector `history` is empty. If true, the function returns an empty string to indicate that there is no chat history.
 * 2. Otherwise, returns `(*this->history)[0](*this->history)[0]` which is the first location of the vector.
 * 
 * @returns This function returns and empty string if the vector `history` is empty. Otherwise, returns the first string of `history`.
 */

std::string ChatHistoryIterator::first(){
    if(this->history->empty()) {
        return "";
    }
    return (*this->history)[0];
}

/**
 * @brief Method to step through the vector
 * @details 
 * 1. Increments `current`.
 * 2. Checks if `current` is less that the size of `history`. If true, returns `(*this->history)[this->current]`. Otherwise returns an empty string.
 * 
 * @returns If, post increment, current is within the size of `history` then the `current` location in the vector. Otherwise, returns an empty string.
 */

std::string ChatHistoryIterator::next(){
    ++this->current;
    if(this->current < this->history->size()) {
        return (*this->history)[this->current];
    } else {
        return "";
    }
}

/**
 * @brief This method checks if the end of the vector has been reached.
 * 
 * @returns If `current` >= the size of vector `history` then the function returns true. Otherwise, the function returns false.
 */

bool ChatHistoryIterator::isDone(){
    return this->current >= this->history->size();
}

/**
 * @brief Method to remove the `current` string from vector `history`.
 */

void ChatHistoryIterator::remove(){
    if(this->current < this->history->size()) {
        this->history->erase(this->history->begin() + this->current);
        if(this->current >= this->history->size() && this->current > 0) {
            --this->current;
        }
    }
}

/**
 * @brief Method to get the `current` string in the vector.
 * 
 * @returns This method returns the `current` location in the vector if current is less than the vectors size. Otherwise, returns an empty string
 * 
 */

std::string ChatHistoryIterator::currentItem(){
    if(this->current < this->history->size()) {
        return (*this->history)[this->current];
    } else {
        return "";
    }
}

/**
 * @brief Destructor for the `ChatHistoryIterator` class.
 */

ChatHistoryIterator::~ChatHistoryIterator() {
    history = nullptr;
}
