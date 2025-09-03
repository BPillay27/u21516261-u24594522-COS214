#include "SpecialMenu.h"

SpecialMenu::SpecialMenu():Menus(){

}

SpecialMenu::~SpecialMenu(){

}

void SpecialMenu::notifyObservers(std::string message){
    size_t tester=message.find(" has been added");
    std::string notice=message;
    if(tester==std::string::npos){
        //this is for a pizza being removed
        notice=notice+" from the specials";
    }else{
        notice=notice+" to the specials";
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