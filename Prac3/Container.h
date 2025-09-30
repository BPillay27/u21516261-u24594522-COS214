#ifndef CONTAINER_H
#define CONTAINER_H
#include "Iterator.h"
#include <list>
#include <vector>
#include <string>
class Users;

/**
 * @defgroup Concrete_Aggregates
 * @brief The concrete implementations of the Abstract Container class
 * @ingroup Iterator_Pattern
 */

/**
 * @defgroup Aggregates
 * @brief The abstract base class for Concrete Aggregates to inherit from.
 * @ingroup Iterator_Pattern
 */

/**
 * @class Container
 * @brief The container for an object.
 * @details This is the abstract `Aggregate` class which `UserList` and `ChatHistory` will inherit from. Has pure virtual function `createIterator`.
 * 
 * @ingroup Aggregates
 */


class Container {
    public:
        virtual Iterator* createIterator()=0;
        Container(){};
        virtual ~Container(){};
};

/**
 * @class UserList
 * @brief This is a container for Users.
 * 
 * @details This is a container for `Users`. Its' implementation of `createIterator()` returns a `UserIterator` to step through a list of `Users`.
 * @ingroup Concrete_Aggregates
 */

class UserList: public Container {
    private:
        /**
         * @brief The list of `Users` objects managed by the container.
         */
        std::list<Users*> users;
    public:
        UserList();
        void addUser(Users* user);
        void removeUser(Users* user);
        Iterator* createIterator() override;
        ~UserList();
};

/**
 * @class ChatHistory
 * @brief This is a container for a vector of strings.
 * 
 * @details This is a container for strings. Its' implementation of `createIterator()` returns a `ChatHistoryIterator` to step through a list of `ChatHistory`.
 * @ingroup Concrete_Aggregates
 */

class ChatHistory: public Container {
    private:
        /**
         * @brief The vetcor of string `message` objects which were sent to a `ChatRoom`.
         */
        std::vector<std::string> history;
    public:
        ChatHistory();
        void add(const std::string message);
        void remove(const std::string& message);
        Iterator* createIterator() override;
        ~ChatHistory();
};

#include "Users.h"
#endif // CONTAINER_H