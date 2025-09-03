#include "Menus.h"

Menus::Menus(){
}

Menus::~Menus(){
    observers.clear();
    for(auto piz:pizzas){
        delete piz;
    }
    pizzas.clear();
}

void Menus::addObserver(Observer* observer){
    if (observer == nullptr)
        return;
    observers.push_back(observer);
}

void Menus::removeObserver(Observer* observer){
    if(observer== nullptr){
        return;
    }
    observers.erase(
        std::remove(observers.begin(), observers.end(), observer),
        observers.end()
    );
}

void Menus::addPizza(Pizza* pizza){
    if(pizza==nullptr){
        return;
    }
    pizzas.push_back(pizza);
    //std::string adder=" has been added"
    std::string notice=pizza->getName()+" has been added";
    notifyObservers(notice);
}

void Menus::removePizza(Pizza* pizza){
    if(pizza==nullptr){
        return;
    }
    pizzas.erase(
        std::remove(pizzas.begin(), pizzas.end(), pizza),
        pizzas.end()
    );
    std::string notice=pizza->getName()+" was removed";
    notifyObservers(notice);
    delete pizza;
}

Pizza* Menus::MenuIndex(int index){
    if(!pizzas.empty()){
        
        if(index<0 || index-1>=pizzas.size()){
            return nullptr;
        }
        Pizza* returner=nullptr;
        returner=pizzas.at(index-1)->clone();
        return returner;
        try{

        }catch(const std::out_of_range& e){
            std::cout<<"That is not in this menu"<<std::endl;
            return nullptr;
        }
    }
    return nullptr;
}