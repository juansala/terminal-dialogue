#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "terminal_dialogue/graphics/geometry.hpp"

namespace default_color_pairs = ncurses_wrapper::default_color_pairs;

class Rectangle : public Shape {
public:
  using ColorPair = ncurses_wrapper::ColorPair;
  Rectangle() {}
  Rectangle(int x, int y, char pixel_type, int width, int height, 
            ColorPair fill = default_color_pairs::kClassic,
            ColorPair border = default_color_pairs::kClassic);
  ~Rectangle() {}

  // Draw the rectangle with the upper-left vertex at the origin defined by m_x
  // and m_y. Intended usage is a call by a Renderer object that draws the 
  // entire graphical frame.
  virtual void Draw() override;

  void SetWidth(int width) { m_width = width; }
  void SetWeight(int height) { m_height = height; }

private:
  int m_width;
  int m_height;
};

#endif