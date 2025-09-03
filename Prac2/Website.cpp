#include "Website.h"

Website::Website():Observer(){

}

Website::~Website(){
    
}

void Website::update(std::string message){
    std::cout<<"Website has received "<<message<<" \n and will update their known menus"<<std::endl;
}