#ifndef ORDER_H
#define ORDER_H

#include "Pizza.h"
#include <list>
#include "Pick.h"

#include "Process.h"

class Order{
public: 
    void next();
    bool setState(Process* next);
    bool addPizza(Pizza* ordering);
    Order();
    ~Order();
    int getCount();
private:
    std::list<Pizza*> pizzas;
    Process* state;
};

#endif