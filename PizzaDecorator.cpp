#include "PizzaDecorator.h"

PizzaDecorator::PizzaDecorator(Pizza *pizza)
{
    if (pizza != nullptr)
    {
        this->pizza = pizza;
    }
}

PizzaDecorator::~PizzaDecorator()
{
    if (pizza != nullptr)
    {
        delete pizza;
        pizza=nullptr;
    }
}

void PizzaDecorator::add(Pizza* extra){
    if(extra==nullptr){
        return;
    } else{
        if(pizza==nullptr){
            pizza=extra;
        } 
    }
}