#include "Container.h"

/**
 * @brief Constructor for the UserList class
 * @details This is the constructor for the UserList class. This constructor creates and empty list of `Users`.
 */

UserList::UserList() {
    // Constructor implementation
    this->users=std::list<Users*>();
}

/**
 * @brief Method to add user to list.
 * @details 
 * 1. Checks if `user` is `nullptr`. If true, return.
 * 2. Create a `UserIterator`.
 * 3. Step through the list. If `user` already exists in the list, delete `Iterator` and return.
 * 4. Delete `Iterator`.
 * 5. Push `User` into the list
 * 
 * @param user The User object which will be added to the list
 */

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

/**
 * @brief Removes a User from the list
 * @details 
 * 1. Checks if `user` is `nullptr`. If true, return.
 * 2. Create a `UserIterator`.
 * 3. Steps through the list. If the `User` is found, delete the `User`, then delete the `Iterator`, then return.
 * 4. If the `User` is not found at the end of the list, delete the `Iterator` and return
 * 
 * @param user The `Users` object which will be removed from the list
 * 
 * @note If the `Users` object is not a part of the list, this function will make no changes to the list.
 */

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

/**
 * @brief Returns a `UserIterator` object with `users`
 * @returns `new UserIterator(&this->users)`
 */

Iterator* UserList::createIterator() {
    return new UserIterator(&this->users);
}

/**
 * @brief Destructor for the UserList class.
 */

UserList::~UserList() {
    // Destructor implementation
    for(auto user : this->users) {
        user = nullptr;
    }
    this->users.clear();
}

/**
 * @brief Constructor for the ChatHistory class.
 * @details Initialises the `history` member variable to an empty vector.
 */

ChatHistory::ChatHistory() {
    // Constructor implementation
    this->history=std::vector<std::string>();
}

/**
 * @brief Method to add a `message` to the vector.
 * @details Pushes the `message` to the back of the vector.
 * 
 * @param message The string the `User` has sent.
 * 
 * @warning Can add an empty string to the vector.
 */

void ChatHistory::add(const std::string message) {
    this->history.push_back(message);
}

/**
 * @brief ChatHistory implementation of createIterator.
 * @returns `new ChatHistoryIterator(&this->history)`
 */

Iterator* ChatHistory::createIterator() {
    return new ChatHistoryIterator(&this->history);
}

/**
 * @brief Destructor for the ChatHistory class
 */

ChatHistory::~ChatHistory() {
    // Destructor implementation
    this->history.clear();
}

/**
 * @brief Method to remove a message from the vector
 * @details
 * 1. Creates a `ChatHistoryIterator`.
 * 2. Steps through the messages, if `message` is found delete it, then delete the `Iterator` and return.
 * 3. If not found, delete the `Iterator` and return.
 * 
 * @param message
 * @note This method does not affect the vector if the message is not found.
 */

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
