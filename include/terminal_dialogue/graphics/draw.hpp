#ifndef DRAW_HPP
#define DRAW_HPP

#include <ncurses.h>

// This file is meant to lay a newer, easier interface for drawing graphics in
// a text-based terminal using ncurses under the hood. It is meant to hide away
// the interface established by ncurses. To learn about the actual ncurses
// interface, please refer to online resources (e.g. Ncurses Programming Guide
// by J.B. Wyatt) or check out the library source code.

// TODO(juansala): Convert raw pointers to smart pointers.

using Window = WINDOW;

struct CharAttributes
{
  // TODO(juansala): Check type conversions.
  static const unsigned int normal = A_NORMAL;             // Normal display (no highlight)
  static const unsigned int highlight = A_STANDOUT;        // Highlighting
  static const unsigned int underline = A_UNDERLINE;       // Underlining
  static const unsigned int reverse_video = A_REVERSE;     // Reverse video
  static const unsigned int blinking = A_BLINK;            // Blinking
  static const unsigned int dim = A_DIM;                   // Half bright
  static const unsigned int bold = A_BOLD;                 // Extra bright or bold
  static const unsigned int protect = A_PROTECT;           // Protected mode
  static const unsigned int invisible = A_INVIS;           // Invisible or blank mode
  static const unsigned int alt_char_set = A_ALTCHARSET;   // Alternate character set
  static const unsigned int extract = A_CHARTEXT;          // Bit-mask to extract a character
  // TODO(juansala): Handle color pairs.
};

void initialize_ncurses(bool one_char, bool no_echo, bool special_keys, 
                        bool use_color);

void restore_terminal_settings();

int read_input();

void add_pixel_char(int x, int y, char pixel_type, Window* win_ptr = nullptr, 
                    char attribute = CharAttributes::normal);

#endif