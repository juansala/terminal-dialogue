#include <iostream>
#include "terminal_dialogue/graphics/rectangle.hpp"

Rectangle::Rectangle() {}

Rectangle::~Rectangle() {}

void Rectangle::draw()
{
  std::cout << "In Rectangle.draw" << std::endl;
}