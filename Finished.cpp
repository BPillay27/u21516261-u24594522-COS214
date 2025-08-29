#include "Finished.h"

Finished::Finished(Order *order) : Process(order)
{
}

void Finished::proceed()
{
    std::cout<<"Order is complete...\n";
}