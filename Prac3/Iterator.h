#ifndef ITERATOR_H
#define ITERATOR_H

class Users;
#include <list>
#include <vector>
#include <string>

/**
 * @defgroup Iterator Iterator Pattern
 * @brief Collection of classes that participate in the Iterator design pattern
 */

/**
 * @defgroup Concrete 
 */

 /**
  * @class Iterator
  * @brief This is the abstract Iterator class
  * @details This is the abstract Iterator class which will be the base class for 
  * @ingroup Iterator
  */

class Iterator {
    public:
        virtual bool isDone()=0;
        virtual void remove()=0;
        virtual ~Iterator() = default;
};

/**
 * @defgroup ConcreteIterators
 * @brief These are the concrete implementations of `Iterator`.
 */

/**
 * @class UserIterator
 * @brief Class to iterate over a list of Users.
 * @details This class is responsible for providing an interface to step through a list of `Users` objects.
 * @ingroup ConcreteIterators
 */

class UserIterator: public Iterator {
    private:
        std::list<Users*>* users;
        std::list<Users*>::iterator current;
        std::list<Users*>::iterator start;
        std::list<Users*>::iterator end;
    public:
        UserIterator(std::list<Users*>* list);
        Users* first();
        Users* next();
        bool isDone() override;
        void remove() override;
        Users* currentItem();
        ~UserIterator();
};

/**
 * @class ChatHistoryIterator
 * @brief Class to iterate over a vector of strings.
 * @details This class is responsible for providing an interface to step through a vector of `message` strings from `Users`.
 * @ingroup ConcreteIterators
 */

class ChatHistoryIterator: public Iterator {
    private:
        std::vector<std::string>* history;                      
        int current;             
    public:
        ChatHistoryIterator(std::vector<std::string>* history); 
        std::string first();        
        std::string next();        
        bool isDone() override;     
        void remove() override;     
        std::string currentItem();  
        ~ChatHistoryIterator();     
};                              

#include "Users.h"

#endif // ITERATOR_H