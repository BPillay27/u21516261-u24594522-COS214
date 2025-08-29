#include <iostream>
#include "TomatoSauce.h"
#include "Topping.h"
#include "ToppingGroup.h"
#include "Salami.h"
//#include "PizzaComponent.h"
#include "Mushrooms.h"
#include "Olives.h"
#include "Onions.h"
#include "Pepperoni.h"
#include "GreenPeppers.h"
#include "FetaCheese.h"
#include "Cheese.h"
#include "BeefSausage.h"
#include "BasePizza.h"
#include "Pizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "PizzaDecorator.h"

int main(){
    PizzaComponent* Mushroom=new Mushrooms();
    PizzaComponent* Green=new GreenPeppers();
    PizzaComponent* onions=new Onions();
    PizzaComponent* dough=new Pepperoni();
    ToppingGroup vegetarian=ToppingGroup("Vegetarian");
    PizzaComponent* m=vegetarian.clone();
    ToppingGroup VegetarianDeluxe=ToppingGroup("Vegetarian Deluxe");
    vegetarian.add(Mushroom);
    vegetarian.add(Green);
    vegetarian.add(onions);
    vegetarian.add(dough);
    std::cout<<vegetarian.getName()<<" , Price: R"<<vegetarian.getPrice()<<std::endl;
    vegetarian.remove(dough);
    VegetarianDeluxe.add(m);

    std::cout<<vegetarian.getName()<<" , Price: R"<<vegetarian.getPrice()<<std::endl;
    
    
    std::cout<<"\n"<<"TESTING DECORATOR"<<"\n";
    PizzaComponent* _Mushroom=new Mushrooms();
    Pizza* piz=new BasePizza(_Mushroom); //fine
    Pizza* _extra_cheese=new ExtraCheese(piz);
    Pizza* _stuffed=new StuffedCrust(_extra_cheese);
    _stuffed->printPizza();
    _extra_cheese->printPizza();
    _stuffed->printPizza();
    delete _stuffed;
    //deleted dough class and added the price in the base Pizza because all Pizza has dough.
    
    return 0;
    
}