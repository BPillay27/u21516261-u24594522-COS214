#include "Prepare.h"

Prepare::Prepare(Order *order) : Process(order)
{
}

void Prepare::proceed()
{
    std::cout<<"The chiefs are preparing your order"<<std::endl;
    Process *temp = new Finished(order);
    order->setState(temp);
}