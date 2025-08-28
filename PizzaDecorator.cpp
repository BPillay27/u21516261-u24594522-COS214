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
    }
}