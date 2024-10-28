#include "terminal_dialogue/graphics/shape.hpp"

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

Shape::Shape(int x, int y, char pixel_type)
  : Geometry{ x, y, pixel_type }
{}