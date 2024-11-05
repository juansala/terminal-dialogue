#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "terminal_dialogue/graphics/draw.hpp"

class Geometry
{
public:
  Geometry() {}
  Geometry(int x, int y, char pixel_type, const Color& fill, 
           const Color& border);
  ~Geometry() {} // TODO(juansala): Make virtual?

  virtual void draw() {}
  int get_x() { return m_x; }
  int get_y() { return m_y; }

  void set_origin(int x, int y);
  void set_fill_rgba(const Color& color) { m_fill = color; }
  void set_border_rgba(const Color& color) { m_border = color; }
  void set_pixel_type(char c) { m_pixel_type = c; }

protected:
  int m_x;
  int m_y;
  char m_pixel_type;
  Color m_fill;
  Color m_border;
};

// TODO(juansala): Add tile functionality.
class Shape : public Geometry
{
public:
  Shape() {}
  Shape(int x, int y, char pixel_type, const Color& fill, const Color& border);
  ~Shape() {}
};

#endif