#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Observer.h"
//#include "Order.h"

class Customer: public Observer{
    private:
        //Order* order;
    public:
        Customer();
        ~Customer();
        void update(std::string message);
        void makeOrder();
        void Proceed();
        //
};

#endif