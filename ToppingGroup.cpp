#include "ToppingGroup.h"


ToppingGroup::ToppingGroup(std::string name) : PizzaComponent(0,name)
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
    delete component;
}

std::string ToppingGroup::getName()
{
    std::string returner="";
    returner+=this->name+" (";
    for(std::list<PizzaComponent*>::iterator top=toppings.begin(); top!=toppings.end();++top){
        returner+=(*top)->getName();
        std::list<PizzaComponent*>::iterator next = top;
        ++next;
        if(next!=toppings.end()){
            returner+=", ";
        }
    }   
    returner+=")";
    return returner;
}

double ToppingGroup::getPrice()
{
    double thePrice=0;
    for(auto prices: toppings){
        thePrice+=prices->getPrice();
    }
    return thePrice;
}

ToppingGroup::ToppingGroup(const ToppingGroup &old):PizzaComponent(old){
    for(std::list<PizzaComponent*>::const_iterator top=old.toppings.begin(); top!=old.toppings.end();++top){
        this->toppings.push_back((*top)->clone());
    }
}

PizzaComponent* ToppingGroup::clone(){
    return new ToppingGroup(*this);
}