#ifndef FINISHED_H
#define FINISHED_H

#include "Process.h"
#include "Order.h"
#include <iostream>

class Finished : public Process{
    public:
    Finished(Order* order);
    void proceed();
};

#endif