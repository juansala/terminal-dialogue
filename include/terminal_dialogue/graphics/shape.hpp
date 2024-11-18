#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>

#include "terminal_dialogue/graphics/ncurses_wrapper.hpp"

class Geometry
{
public:
  using SharedPtr = std::shared_ptr<Geometry>;
  using ColorPair = ncurses_wrapper::ColorPair;
  Geometry() {}
  Geometry(int x, int y, char pixel_type);
  ~Geometry() {} // TODO(juansala): Make virtual?

  virtual void draw() {}
  int get_x() { return m_x; }
  int get_y() { return m_y; }

  void set_origin(int x, int y);
  void set_pixel_type(char c) { m_pixel_type = c; }

protected:
  int m_x;
  int m_y;
  char m_pixel_type;
};

// TODO(juansala): Add tile functionality.
class Shape : public Geometry
{
public:
  Shape() {}
  Shape(int x, int y, char pixel_type, ColorPair fill, ColorPair border);
  ~Shape() {}

  virtual void draw() {}

  void set_fill_rgba(ColorPair color) { m_fill = color; }
  void set_border_rgba(ColorPair color) { m_border = color; }
  
protected:
  ColorPair m_fill;
  ColorPair m_border;
};

#endif