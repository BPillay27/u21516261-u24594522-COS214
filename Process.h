#ifndef PROCESS_H
#define PROCESS_H

#include "Order.h"

class Process
{
public:
    virtual void proceed() = 0;
    Process(Order* order);
    virtual ~Process();

protected:
    Order *order;
};
#endif
