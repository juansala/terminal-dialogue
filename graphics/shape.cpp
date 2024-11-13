#include "terminal_dialogue/graphics/shape.hpp"

Geometry::Geometry(int x, int y, char pixel_type, 
                   const ncurses_wrapper::ColorPair fill, 
                   const ncurses_wrapper::ColorPair border)
  : m_x{ x },
    m_y{ y },
    m_pixel_type{ pixel_type },
    m_fill{ fill },
    m_border { border }
{}

void Geometry::set_origin(int x, int y)
{
  m_x = x;
  m_y = y; 
}

Shape::Shape(int x, int y, char pixel_type, 
             const ncurses_wrapper::ColorPair fill, 
             const ncurses_wrapper::ColorPair border)
  : Geometry{ x, y, pixel_type, fill, border}
{}