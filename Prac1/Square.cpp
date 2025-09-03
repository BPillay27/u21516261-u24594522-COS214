#include "Square.h"

Square::Square() : Shape()
{
}

Square::Square(const Square &other) : Shape(other)
{
}

Shape *Square::clone()
{
    return new Square(*this);
}

bool Square::changeLength(int length)
{
    if (length < 0)
        return false;
    Shape::changeLength(length);
    Shape::changeWidth(length);
    return true;
}

bool Square::changeWidth(int width)
{
    if (width < 0)
        return false;
    Shape::changeLength(width);
    Shape::changeWidth(width);
    return true;
}