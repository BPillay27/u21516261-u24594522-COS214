#include <iostream>
#include "TomatoSauce.h"
#include "Topping.h"
#include "ToppingGroup.h"
#include "Salami.h"
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
#include "SpecialMenu.h"
#include "Customer.h"
#include "PizzaMenu.h"
#include "Website.h"
#include "Order.h"


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
    vegetarian.add(nullptr);
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
    std::cout<<"\nTESTING the cloning for Pizza classes\n";
    std::cout<<"\n The original\n";
    _stuffed->printPizza();
    std::cout<<"\n The clone\n";
    Pizza* twoStuffed=_stuffed->clone();
    twoStuffed->printPizza();
    delete _stuffed;// cloning up to the Pizza class works
    
    std::cout<<"\nTesting the Observers\n";
    Observer* c=new Customer();
    Observer* w=new Website();
    Observer* t=new Customer();
    c->update("Help");
    w->update("More Help");
    
    std::cout<<"\nTesting the Menus\n";
    ToppingGroup bigPizza=ToppingGroup("Meat lovers");
    bigPizza.add(new Pepperoni());
    bigPizza.add(new BeefSausage());
    PizzaComponent* addition=bigPizza.clone();
    Pizza* extras=twoStuffed->clone();
    SpecialMenu special=SpecialMenu();
    special.addObserver(c);
    special.addObserver(w);
    special.addObserver(t);
    special.addPizza(twoStuffed);
    special.addPizza(extras);
    special.removePizza(extras);
    Pizza* result=special.MenuIndex(1);
    result->printPizza();
    Pizza* another=new BasePizza(addition);
    std::cout<<"\n Testing the PizzaMenu\n"<<std::endl;
    PizzaMenu myMenu=PizzaMenu();
    myMenu.addObserver(c);
    myMenu.addObserver(w);
    myMenu.addObserver(t);
    myMenu.addPizza(another);
    myMenu.addPizza(result);

    std::cout<<"\n\t Testing the state and strategy design patterns\n\t ****************\n";
    Customer timmy=Customer();
    
    Pizza* re=another->clone();
    
    timmy.makeOrder();
    timmy.addToOrder(another->clone());
    timmy.addToOrder(re);
    timmy.Proceed();
    timmy.Proceed();
    timmy.Proceed();
    timmy.Proceed();
    //deleted dough class and added the price in the base Pizza because all Pizza has dough.
    delete t;
    delete c;
    delete w;
    return 0;
    
}