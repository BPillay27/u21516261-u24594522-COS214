#include "StuffedCrust.h"

StuffedCrust::StuffedCrust(Pizza *pizza) : PizzaDecorator(pizza)
{
}

StuffedCrust::~StuffedCrust()
{

}

std::string StuffedCrust::getName()
{
    return "Stuffed Crust";
}

double StuffedCrust::getPrice()
{
    return 20;
} 