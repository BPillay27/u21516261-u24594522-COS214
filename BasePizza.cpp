#include "BasePizza.h"
double BasePizza::getPrice()
{
    return toppings->getPrice()+10;//10 is for the dough
}
std::string BasePizza::getName()
{
    return toppings->getName();
}
BasePizza::BasePizza(PizzaComponent* topping): Pizza()
{
    if (topping != nullptr)
    {
        this->toppings= topping;
    }
}

BasePizza::~BasePizza()
{
    if(toppings!=nullptr){
        delete toppings;
    }
    toppings = nullptr;
}

Pizza* BasePizza::clone(){
    return new BasePizza(*this);
}

BasePizza::BasePizza(const BasePizza &old):Pizza(old){
    this->toppings=old.toppings->clone();
}
