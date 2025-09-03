#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
public:
    Square();
    Square(const Square &other);
    Shape *clone();
    bool changeLength(int length);
    bool changeWidth(int width);
};
#endif