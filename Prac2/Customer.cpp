#include "Customer.h"

Customer::Customer():Observer(){
    this->order=nullptr;
}

Customer::~Customer(){
    if(order!=nullptr){
        delete order;
    }
    order=nullptr;
}

void Customer::update(std::string message){
    std::cout<<"Customer has received "<<message<<" \n and will update their known menus"<<std::endl;
}

void Customer::makeOrder(){
    if(this->order==nullptr){
        this->order=new Order();
    }
}

void Customer::Proceed(){
    if(this->order==nullptr){
        return;
    }
    this->order->next();
}

void Customer::addToOrder(Pizza* pizza){
    if(this->order==nullptr){
        return;
    }else{
        this->order->addPizza(pizza);
    }
}