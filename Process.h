#ifndef PROCESS_H
#define PROCESS_H

class Order;

class Process
{
public:
    virtual void proceed() = 0;
    explicit Process(Order* order);
    virtual ~Process();
    
protected:
    Order *order;
};
#endif