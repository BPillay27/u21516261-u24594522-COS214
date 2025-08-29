#include "website.h"

website::website():Observer(){

}

void website::update(std::string message){
    std::cout<<"Website has received "<<message<<" \n and will update their known menus"<<std::endl;
}