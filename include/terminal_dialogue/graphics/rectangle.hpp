#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "terminal_dialogue/graphics/geometry.hpp"

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

  // Draw the rectangle with the upper-left vertex at the origin defined by m_x
  // and m_y. Intended usage is a call by a Renderer object that draws the 
  // entire graphical frame.
  virtual void draw() override;

  void set_width(int width) { m_width = width; }
  void set_height(int height) { m_height = height; }

private:
  int m_width;
  int m_height;
};

#endif