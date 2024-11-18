#include "terminal_dialogue/graphics/geometry.hpp"

Geometry::Geometry(int x, int y, char pixel_type)
  : m_x{ x },
    m_y{ y },
    m_pixel_type{ pixel_type }
{}

void Geometry::set_origin(int x, int y)
{
  m_x = x;
  m_y = y; 
}

Shape::Shape(int x, int y, char pixel_type, 
             const ncurses_wrapper::ColorPair fill, 
             const ncurses_wrapper::ColorPair border)
  : Geometry{ x, y, pixel_type },
    m_fill{ fill },
    m_border { border }
{}

Point::Point(int x, int y, char pixel_type, ColorPair color)
  : Geometry{ x, y, pixel_type},
    m_color { color }
{}

void Point::draw()
{
  ncurses_wrapper::add_pixel_char(m_x, m_y, m_pixel_type, color);
}

Line::Line(int x_i, int y_i, int x_f, int y_f, char pixel_type, ColorPair color)
  : Geometry { x_i, y_i, pixel_type },
    m_color { color }
{}

// TODO(juansala): Use Bresenham algorithm to draw lines between arbitrary
// points.
void Line::draw()
{}