#include "PizzaMenu.h"


PizzaMenu::PizzaMenu():Menus(){

}

PizzaMenu::~PizzaMenu(){

}

void PizzaMenu::notifyObservers(std::string message){
    size_t tester=message.find(" has been added");
    std::string notice=message;
    if(tester==std::string::npos){
        //this is for a pizza being removed
        notice=notice+" from the menu";
    }else{
        notice=notice+" to the menu";
    }
    for (Observer* ob : observers) {
        if (ob != nullptr) {
            try {
                ob->update(notice);
            } catch (const std::exception& e) {
                // Handle potential exceptions from observer updates
                std::cerr << "Error notifying observer: " << e.what() << std::endl;
            }
        }
    }
    
}