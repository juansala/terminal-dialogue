#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "terminal_dialogue/graphics/geometry.hpp"

class Circle : public Shape
{
public:
  Circle () {}
  Circle(int center_x, int center_y, char pixel_type, ColorPair fill, 
         ColorPair border);
  ~Circle() {}

  virtual void draw() override {}
}

#endif