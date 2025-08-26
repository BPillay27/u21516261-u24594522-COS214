#include "ToppingGroup.h"

ToppingGroup::ToppingGroup(double price, std::string name) : PizzaComponent(price, name)
{
}

ToppingGroup::ToppingGroup() : PizzaComponent()
{
}

ToppingGroup::~ToppingGroup()
{
    for (auto comp : toppings)
    {
        delete comp;
    }
    toppings.clear();
}

void ToppingGroup::add(PizzaComponent *component)
{
    if (component == nullptr)
        return;
    toppings.push_back(component);
}

void ToppingGroup::remove(PizzaComponent *component)
{
    if (component == nullptr)
        return;
    toppings.remove(component);
}

std::string ToppingGroup::getName()
{
    PizzaComponent::getBaseName();
}

double ToppingGroup::getPrice()
{
    PizzaComponent::getBasePrice();
}