#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
private:
    int length;
    int width;
    std::string colour;
    int position_x;
    int position_y;

public:
    Shape();
    virtual ~Shape() = default;
    Shape(int length, int width, int position_x, int position_y);
    Shape(const Shape &other);
    virtual Shape *clone() = 0; // pure virtual for the prototype design pattern
    bool changeLength(int length);
    bool changeWidth(int width);
    bool changeColour(std::string colour);
    bool changePosition(int position_x, int position_y);
    void virtual toString();
};
#endif