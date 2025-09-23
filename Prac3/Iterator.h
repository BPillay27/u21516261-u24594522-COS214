#ifndef ITERATOR_H
#define ITERATOR_H

class Users;
#include <list>
#include <vector>
#include <string>

class Iterator {
    public:
        virtual bool isDone()=0;
        virtual void remove()=0;
        virtual ~Iterator() = default;
};

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