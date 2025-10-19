#include "terminal_dialogue/graphics/geometry.hpp"

Geometry::Geometry(int x, int y, char pixel_type)
  : m_x{ x },
    m_y{ y },
    m_pixel_type{ pixel_type } {}

void Geometry::SetOrigin(int x, int y) {
  m_x = x;
  m_y = y; 
}

Shape::Shape(int x, int y, char pixel_type, 
             const ncurses_wrapper::ColorPair fill, 
             const ncurses_wrapper::ColorPair border)
  : Geometry{ x, y, pixel_type },
    m_fill{ fill },
    m_border { border } {}

Point::Point(int x, int y, char pixel_type, ColorPair color)
  : Geometry{ x, y, pixel_type},
    m_color { color } {}

void Point::Draw() {
  ncurses_wrapper::AddPixelChar(m_x, m_y, m_pixel_type, m_color);
}

Line::Line(int x_i, int y_i, int x_f, int y_f, char pixel_type, ColorPair color)
  : Geometry { x_i, y_i, pixel_type },
    m_x_end { x_f },
    m_y_end { y_f },
    m_color { color } {}

void Line::Draw() {
  // TODO(juansala): Refactor Bresenham to get points and then draw the points
  DrawLine(m_x, m_y, m_x_end, m_y_end);
}