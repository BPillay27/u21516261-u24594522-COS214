#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

class Observer{
    Observer(){};
    virtual void update(std::string message)=0;
}

#endif //closed the defination of observer class here