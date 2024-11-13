#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "terminal_dialogue/graphics/draw.hpp"

class Geometry
{
public:
  using ColorPair = ncurses_wrapper::ColorPair;
  Geometry() {}
  Geometry(int x, int y, char pixel_type, ColorPair fill, ColorPair border);
  ~Geometry() {} // TODO(juansala): Make virtual?

  virtual void draw() {}
  int get_x() { return m_x; }
  int get_y() { return m_y; }

  void set_origin(int x, int y);
  void set_fill_rgba(ColorPair color) { m_fill = color; }
  void set_border_rgba(ColorPair color) { m_border = color; }
  void set_pixel_type(char c) { m_pixel_type = c; }

protected:
  int m_x;
  int m_y;
  char m_pixel_type;
  ColorPair m_fill;
  ColorPair m_border;
};

// TODO(juansala): Add tile functionality.
class Shape : public Geometry
{
public:
  Shape() {}
  Shape(int x, int y, char pixel_type, ColorPair fill, ColorPair border);
  ~Shape() {}
};

#endif