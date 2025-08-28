#include "ExtraCheese.h"

ExtraCheese::ExtraCheese(Pizza* pizza) : PizzaDecorator(pizza)
{
}
ExtraCheese::~ExtraCheese()
{

}
std::string ExtraCheese::getName()
{
    std::string returner="Extra Cheese "+this->pizza->getName();
    return returner;
}
double ExtraCheese::getPrice()
{
    double total=12+this->pizza->getPrice();
    return total;
}
