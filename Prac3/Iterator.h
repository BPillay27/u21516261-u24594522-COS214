#ifndef ITERATOR_H
#define ITERATOR_H

class Users;
#include <list>
#include <vector>
#include <string>

/**
 * @defgroup Iterator_Pattern
 * @brief Collection of classes that participate in the Iterator Design Pattern.
 */

/**
 * @defgroup Iterators
 * @brief Collection of classes that participate in the Iterator design pattern
 * @ingroup Iterator_Pattern
 */

/**
 * @defgroup Concrete_Iterators
 * @brief Collection of classes that provide a concrete implementation of an Iterator
 * @ingroup Iterator_Pattern
 */

 /**
  * @class Iterator
  * @brief This is the abstract Iterator class
  * @details This is the abstract Iterator class which will be the base class for 
  * @ingroup Iterators
  */

class Iterator {
    public:
        virtual bool isDone()=0;
        virtual void remove()=0;
        virtual ~Iterator() = default;
};

/**
 * @class UserIterator
 * @brief Class to iterate over a list of Users.
 * @details This class is responsible for providing an interface to step through a list of `Users` objects.
 * @ingroup Concrete_Iterators
 */

class UserIterator: public Iterator {
    private:
        /**
         * @brief List of `Users` in the `Iterator`.
         */
        std::list<Users*>* users;
        /**
         * @brief The current item in `users` which the `Iterator` is referring to.
         */
        std::list<Users*>::iterator current;
        /**
         * @brief The 1st item in `users`.
         */
        std::list<Users*>::iterator start;
        /**
         * @brief The last item in `users`.
         */
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
 * @ingroup Concrete_Iterators
 */

class ChatHistoryIterator: public Iterator {
    private:
        /**
         * @brief The vector of strings that represent the Chat History.  
         */
        std::vector<std::string>* history;
        /**
         * @brief The string item the Iterator is currently pointing to.
         */            
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