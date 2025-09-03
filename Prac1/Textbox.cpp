#include "Textbox.h"
#include <iostream>

TextBox::TextBox() : Shape()
{
    this->text = "";
}

TextBox::TextBox(const TextBox &other) : Shape(other)
{
    this->text = other.text;
}

Shape *TextBox::clone()
{
    return new TextBox(*this);
}

std::string TextBox::getText() const
{
    return this->text;
}

bool TextBox::setText(std::string text)
{
    this->text = text;
    return true;
}

void TextBox::toString()
{
    Shape::toString();
    std::cout << "TextBox's text: " << this->text << std::endl;
}