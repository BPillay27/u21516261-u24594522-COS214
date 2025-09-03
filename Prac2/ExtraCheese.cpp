#include "ExtraCheese.h"

ExtraCheese::ExtraCheese(Pizza* pizza): PizzaDecorator(pizza)
{

}
ExtraCheese::~ExtraCheese()
{
    
}

std::string ExtraCheese::getName()
{
    if(pizza!=nullptr){
    std::string returner="Extra Cheese "+this->pizza->getName();
    return returner;
    }
    return "Extra Cheese";
}
double ExtraCheese::getPrice()
{
    if(pizza!=nullptr){
        double total=12+this->pizza->getPrice();
        return total;
    }
    return 12;
}

Pizza* ExtraCheese::clone(){
    return new ExtraCheese(*this);
}

ExtraCheese::ExtraCheese(const ExtraCheese &old):PizzaDecorator(old){

}