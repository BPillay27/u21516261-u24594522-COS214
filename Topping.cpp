#include "Topping.h"

Topping::Topping(double price, std::string name) : PizzaComponent(price, name)
{
}

std::string Topping::getName()
{
    return this->name;
}

double Topping::getPrice()
{
    return this->price;
}

Topping::~Topping(){

}

Topping::Topping(const Topping &old):PizzaComponent(old){

}

PizzaComponent* Topping::clone(){
    return new Topping(*this);
}