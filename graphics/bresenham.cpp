#include "terminal_dialogue/graphics/bresenham.hpp"

void draw_h_line(int x_i, int y_i, int x_f, int y_f)
{
  int dx = x_f - x_i;
  int dy = y_f - y_i;

  int y_inc = 1;
  if (dy < 0)
  {
    y_inc = -1;
    dy *= -1;
  }

  int decision_val = (2 * dy) - dx;
  int y = y_i;

  for (int x = x_i; x <= x_f; x++)
  {
    // TODO(juansala): Replace add_pixel_char.
    add_pixel_char(x, y, 'X', ncurses_wrapper::DefaultColorPairs::CLASSIC);
    if (decision_val > 0)
    {
      y = y + y_inc;
      decision_val += 2 * (dy - dx);
    }
    else
    {
      decision_val += 2 * dy;
    }
  }
}

void draw_v_line(int x_i, int y_i, int x_f, int y_f)
{
  int dx = x_f - x_i;
  int dy = y_f - y_i;

  int x_inc = 1;
  if (dx < 0)
  {
    x_inc = -1;
    dx *= -1;
  }

  int decision_val = (2 * dx) - dy;
  int x = x_i;

  for (int y = y_i; y <= y_f; y++)
  {
    // TODO(juansala): Replace add_pixel_char.
    add_pixel_char(x, y, 'X', ncurses_wrapper::DefaultColorPairs::CLASSIC);
    if (decision_val > 0)
    {
      x = x + x_inc;
      decision_val += 2 * (dx - dy);
    }
    else
    {
      decision_val += 2 * dx;
    }
  }
}

void draw_line(int x_i, int y_i, int x_f, int y_f)
{
  if (abs(y_f - y_i) < abs(x_f - x_i))
  {
    if (x_i > x_f)
      draw_h_line(x_f, y_f, x_i, y_i);
    else
      draw_h_line(x_i, y_i, x_f, y_f);
  }
  else
  {
    if (y_i > y_f)
      draw_v_line(x_f, y_f, x_i, y_i);
    else
      draw_v_line(x_i, y_i, x_f, y_f);
  }
}