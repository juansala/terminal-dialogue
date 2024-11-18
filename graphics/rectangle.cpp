#include "terminal_dialogue/graphics/rectangle.hpp"

Rectangle::Rectangle(int x, int y, char pixel_type, int width, int height, 
                     ncurses_wrapper::ColorPair fill, 
                     ncurses_wrapper::ColorPair border)
  : Shape{ x, y, pixel_type, fill, border},
    m_width{ width },
    m_height{ height }
{}

void Rectangle::draw()
{
  // TODO(juansala): Try iterating over y first, then x to follow memory.
  for (int i = m_x; i < m_x + m_width; i++)
  {
    for (int j = m_y; j < m_y + m_height; j++)
    {
      if (i == m_x 
          || i == (m_x + m_width - 1) 
          || j == m_y 
          || j == (m_y + m_height - 1))
        ncurses_wrapper::add_pixel_char(i, j, m_pixel_type, m_border);
      else
        ncurses_wrapper::add_pixel_char(i, j, m_pixel_type, m_fill);
    }
  }
}