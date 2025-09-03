#include "PizzaComponent.h"

PizzaComponent::PizzaComponent(double price, std::string name)
{
    this->price = price;
    this->name = name;
}

PizzaComponent::~PizzaComponent(){
    
}


PizzaComponent::PizzaComponent(const PizzaComponent &old){
    this->price=old.price;
    this->name=old.name;
}