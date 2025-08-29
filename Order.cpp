#include "Order.h"

void Order::next()
{
    state->proceed();
}

bool Order::setState(Process *next)
{
    if (next == nullptr)
        return false;

    if (state != nullptr)
    {
        delete state;
        state = nullptr;
    }

    state = next;
    return true;
}

bool Order::addPizza(Pizza *ordering)
{
    if (ordering == nullptr)
        return false;

    pizzas.push_back(ordering);
    return true;
}

Order::Order()
{
    state = new Pick(this);
}

Order::~Order()
{
    for (auto p : pizzas)
    {
        delete p;
    }

    pizzas.clear();

    delete state;
    state = nullptr;
}

int Order::getCount(){
    int count=0;
    for(auto a:pizzas){
        ++count;
    }

    return count;
}