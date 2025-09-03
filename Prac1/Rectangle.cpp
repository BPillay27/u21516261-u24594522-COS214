#include "Rectangle.h"
Rectangle::Rectangle() : Shape()
{
}

Rectangle::Rectangle(const Rectangle &other) : Shape(other)
{
}

Shape *Rectangle::clone()
{
    return new Rectangle(*this);
}
