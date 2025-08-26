#include "PizzaComponent.h"

PizzaComponent::PizzaComponent(double price, std::string name)
{
    this->price = price;
    this->name = name;
}

std::string PizzaComponent::getBaseName()
{
    return name;
}

double PizzaComponent::getBasePrice()
{
    return price;
}