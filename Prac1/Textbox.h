#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"
#include <iostream>

class TextBox : public Shape
{
private:
    std::string text;

public:
    TextBox();
    TextBox(const TextBox &other);
    Shape *clone();
    std::string getText() const;
    bool setText(std::string text);
    void toString();
};
#endif
