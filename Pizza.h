#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <iostream>

class Pizza
{
public:
    Pizza() = default;
    virtual ~Pizza() = default;
    virtual double getPrice() = 0;
    virtual std::string getName() = 0;
    virtual void printPizza();
};

#endif