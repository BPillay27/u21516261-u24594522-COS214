#ifndef BASEPIZZA_H
#define BASEPIZZA_H

#include "PizzaComponent.h"
#include <string>
#include "Pizza.h"

class BasePizza : public Pizza
{
public:
    double getPrice(); //done
    std::string getName(); //done
    BasePizza(PizzaComponent *topping); //done
    ~BasePizza(); //tested
    Pizza* clone();
    BasePizza(const BasePizza &old);

private:
    PizzaComponent* toppings;
};

#endif
