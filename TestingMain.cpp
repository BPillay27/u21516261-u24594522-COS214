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
#include "Dough.h"
#include "Cheese.h"
#include "BeefSausage.h"

int main(){
    PizzaComponent* Mushroom=new Mushrooms();
    PizzaComponent* Green=new GreenPeppers();
    PizzaComponent* onions=new Onions();
    PizzaComponent* dough=new Dough();
    ToppingGroup vegetarian=ToppingGroup("Vegetarian");
    PizzaComponent* m=vegetarian.clone();
    ToppingGroup VegetarianDeluxe=ToppingGroup("Vegetarian Deluxe");
    vegetarian.add(Mushroom);
    vegetarian.add(Green);
    vegetarian.add(onions);
    vegetarian.add(dough);
    std::cout<<vegetarian.getName()<<" ,Price: R"<<vegetarian.getPrice()<<std::endl;
    vegetarian.remove(dough);
    VegetarianDeluxe.add(m);

    std::cout<<vegetarian.getName()<<" ,Price: R"<<vegetarian.getPrice()<<std::endl;

    //delete vegetarian;
    return 0;
}