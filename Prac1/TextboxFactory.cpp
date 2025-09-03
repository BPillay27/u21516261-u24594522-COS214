#include "TextboxFactory.h"

Shape *TextboxFactory::createShape()
{
    toString();
    return new TextBox();
}
void TextboxFactory::toString()
{
    std::cout << "Textbox factory producing square." << std::endl;
}
