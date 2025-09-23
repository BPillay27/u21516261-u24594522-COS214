#ifndef CONTAINER_H
#define CONTAINER_H
#include "Iterator.h"
#include <list>
#include <vector>
#include <string>
class Users;

class Container {
    public:
        virtual Iterator* createIterator()=0;
        Container(){};
        virtual ~Container(){};
};

class UserList: public Container {
    private:
        std::list<Users*> users;
    public:
        UserList();
        void addUser(Users* user);
        void removeUser(Users* user);
        Iterator* createIterator() override;
        ~UserList();
};

class ChatHistory: public Container {
    private:
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