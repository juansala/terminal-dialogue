#ifndef BRESENHAM_HPP
#define BRESENHAM_HPP

#include <cmath>

#include "terminal_dialogue/graphics/ncurses_wrapper.hpp"

// This file declares functions that implement Bresenham's line drawing
// algorithm, which was referenced from Wikipedia (see URL below).
//
// URL: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

void DrawHLine(int x_i, int y_i, int x_f, int y_f);

void DrawVLine(int x_i, int y_i, int x_f, int y_f);

void DrawLine(int x_i, int y_i, int x_f, int y_f);

#endif