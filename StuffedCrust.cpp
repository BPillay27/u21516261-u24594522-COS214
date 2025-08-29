#include "StuffedCrust.h"

StuffedCrust::StuffedCrust(Pizza* pizza) : PizzaDecorator(pizza)
{
}

StuffedCrust::~StuffedCrust()
{

}

std::string StuffedCrust::getName()
{
    std::string returner="Stuffed Crust "+this->pizza->getName();
    return returner;
}

double StuffedCrust::getPrice()
{
    double total=20+this->pizza->getPrice();
    return total;
} 