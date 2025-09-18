#ifndef ITERATOR_H
#define ITERATOR_H

class Users;
#include <list>

class Iterator {
    public:
        virtual Users* first()=0;
        virtual Users* next()=0;
        virtual bool isDone()=0;
        virtual Users* currentItem()=0;
        virtual void remove()=0;
        virtual ~Iterator();
};

class UserIterator: public Iterator {
    private:
        std::list<Users*>* users;
        std::list<Users*>::iterator current;
        std::list<Users*>::iterator start;
        std::list<Users*>::iterator end;
    public:
        UserIterator(std::list<Users*>* list);
        Users* first() override;
        Users* next() override;
        bool isDone() override;
        void remove() override;
        Users* currentItem() override;
        ~UserIterator();
};

#include "Users.h"

#endif // ITERATOR_H