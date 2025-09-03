#ifndef RECTANGLE_h
#define RECTANGLE_h

#include "Shape.h"
#include <iostream>
class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(const Rectangle &other);
    Shape *clone() override;
};

#endif