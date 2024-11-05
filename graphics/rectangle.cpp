#include "terminal_dialogue/graphics/rectangle.hpp"

Rectangle::Rectangle(int x, int y, char pixel_type, int width, int height, 
                     const Color& fill, const Color& border)
  : Shape{ x, y, pixel_type, fill, border},
    m_width{ width },
    m_height{ height }
{}

void Rectangle::draw() 
{
  // TODO(juansala): Handle border pixels
  for (int i = m_x; i < m_x + m_width; i++)
  {
    for (int j = m_y; j < m_y + m_height; j++)
    {
      ncurses_wrapper::add_pixel_char(i, j, m_pixel_type, m_fill);
    }
  }
}