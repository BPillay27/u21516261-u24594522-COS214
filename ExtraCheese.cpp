#include "ExtraCheese.h"

ExtraCheese::ExtraCheese(Pizza *pizza) : PizzaDecorator(pizza)
{
}
ExtraCheese::~ExtraCheese()
{
}
std::string ExtraCheese::getName()
{
    return "Extra Cheese";
}
double ExtraCheese::getPrice()
{
    return 12;
}
