#ifndef PROCESS_H
#define PROCESS_H

#include "Order.h"

class Process
{
public:
    virtual void proceed() = 0;
    Process(Order* order);
    virtual ~Process();
    double getTotalPrice();
protected:
    Order *order;
};
#endif
