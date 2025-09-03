#include "Shape.h"

Shape::Shape()
{
    this->length = 1;
    this->width = 1;
    this->colour = "white";
    this->position_x = 0;
    this->position_y = 0;
}

Shape::Shape(int length, int width, int position_x, int position_y)
{
    if (length < 0 || width < 0)
    {
        this->length = 1;
        this->width = 1;
    }
    else
    {
        this->length = length;
        this->width = width;
    }
    this->colour = "white";
    this->position_x = position_x;
    this->position_y = position_y;
}

Shape::Shape(const Shape &other)
{
    this->length = other.length;
    this->width = other.width;
    this->colour = other.colour;
    this->position_x = other.position_x;
    this->position_y = other.position_y;
}

bool Shape::changeLength(int length)
{
    if (length < 0)
        return false;
    this->length = length;
    return true;
}

bool Shape::changeWidth(int width)
{
    if (width < 0)
        return false;
    this->width = width;
    return true;
}

bool Shape::changeColour(std::string colour)
{
    if (colour.empty())
        return false;
    this->colour = colour;
    return true;
}

bool Shape::changePosition(int position_x, int position_y)
{
    this->position_x = position_x;
    this->position_y = position_y;
    return true;
}

void Shape::toString()
{
    std::cout << "Shape's attributes: " << this->colour << ", Length: " << this->length
              << ", Width: " << this->width
              << ", Position: (" << this->position_x << ", " << this->position_y << ")"
              << std::endl;
}
