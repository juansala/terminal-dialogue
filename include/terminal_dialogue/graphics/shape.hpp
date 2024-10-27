#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ncurses.h>

struct Color
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
};

class Geometry
{
public:
  Geometry() {};
  ~Geometry() {}; // TODO(juansala): Make virtual?

  virtual void draw() {};
  int get_x() { return m_x; };
  int get_y() { return m_y; };

  void set_origin(int x, int y);
  void set_fill_rgba(const Color& color) { m_fill = color; };
  void set_border_rgba(const Color& color) { m_border = color; };
  void set_pixel_type(char c) { m_pixel_type = c; }

private:
  int m_x;
  int m_y;
  Color m_fill;
  Color m_border;
  char m_pixel_type;
};

// TODO(juansala): Add tile functionality.
class Shape : public Geometry
{
public:
  Shape() {};
  ~Shape() {};
};

#endif