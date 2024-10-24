#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "terminal_dialogue/graphics/shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle();
  ~Rectangle();

  void draw() override;
};

#endif