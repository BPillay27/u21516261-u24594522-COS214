#include "Topping.h"

Topping::Topping()
{
}

Topping::Topping(double price, std::string name) : PizzaComponent(price, name)
{
}

std::string Topping::getName()
{
    return PizzaComponent::getBaseName();
}

double Topping::getPrice()
{
    return PizzaComponent::getBasePrice();
}