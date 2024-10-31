#include "terminal_dialogue/graphics/rectangle.hpp"



Rectangle::Rectangle(int x, int y, char pixel_type, int width, int height)
  : Shape{ x, y, pixel_type },
    m_width{ width },
    m_height{ height }
{}

// TODO(juansala, 10/27/2024)
void Rectangle::draw() 
{
  add_pixel_char(m_x, m_y, m_pixel_type);
}