#include "BasePizza.h"
double BasePizza::getPrice()
{
    return toppings->getPrice();
}
std::string BasePizza::getName()
{
    return toppings->getName();
}
BasePizza::BasePizza(PizzaComponent *topping) : Pizza()
{
    if (topping != nullptr)
    {
        this->toppings = topping;
    }
}
BasePizza::~BasePizza()
{
    delete toppings;
    toppings = nullptr;
}
BasePizza::BasePizza() : Pizza()
{
}