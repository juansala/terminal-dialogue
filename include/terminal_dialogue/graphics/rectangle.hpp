#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "terminal_dialogue/graphics/shape.hpp"

class Rectangle : public Shape
{
public:
  using ColorPair = ncurses_wrapper::ColorPair;
  using DefaultColorPairs = ncurses_wrapper::DefaultColorPairs;
  Rectangle() {}
  Rectangle(int x, int y, char pixel_type, int width, int height, 
            ColorPair fill = DefaultColorPairs::CLASSIC,
            ColorPair border = DefaultColorPairs::CLASSIC);
  ~Rectangle() {}

  void draw() override;
  void set_width(int width) { m_width = width; }
  void set_height(int height) { m_height = height; }

private:
  int m_width;
  int m_height;
};

#endif