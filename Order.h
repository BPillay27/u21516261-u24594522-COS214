#ifndef ORDER_H
#define ORDER_H

#include <list>

class Process;
class Pizza;

class Order{
public: 
    void next();
    bool setState(Process* next);
    bool addPizza(Pizza* ordering);
    Order();
    ~Order();
    int getCount();
    double getTotalPrice();
private:
    std::list<Pizza*> pizzas;
    Process* state;
};

#endif
