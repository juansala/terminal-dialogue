#ifndef DRAW_HPP
#define DRAW_HPP

#include <ncurses.h>

// This file is meant to lay a newer, easier interface for drawing graphics in
// a text-based terminal using ncurses under the hood. It is meant to hide away
// the interface established by ncurses. To learn about the actual ncurses
// interface, please refer to online resources (e.g. Ncurses Programming Guide
// by J.B. Wyatt) or check out the library source code.

// TODO(juansala): Convert raw pointers to smart pointers.
// TODO(juansala): Check out this square font: https://strlen.com/square/

using Window = WINDOW;

namespace ncurses_wrapper
{

  struct CharAttributes
  {
    // TODO(juansala): Check type conversions.
    static const unsigned int normal = A_NORMAL;             // Normal display
    static const unsigned int highlight = A_STANDOUT;        // Highlighting
    static const unsigned int underline = A_UNDERLINE;       // Underlining
    static const unsigned int reverse_video = A_REVERSE;     // Reverse video
    static const unsigned int blinking = A_BLINK;            // Blinking
    static const unsigned int dim = A_DIM;                   // Half bright
    static const unsigned int bold = A_BOLD;                 // Bold
    static const unsigned int protect = A_PROTECT;           // Protected mode
    static const unsigned int invisible = A_INVIS;           // Invisible mode
    static const unsigned int alt_char_set = A_ALTCHARSET;   // Alternate char set
    static const unsigned int extract = A_CHARTEXT;          // Bit-mask to extract a character
    // TODO(juansala): Handle color pairs.
  };

  // TODO(juansala): Special chars not displaying properly. Check locale.
  namespace SpecialChars
  {
    inline unsigned int block = ACS_BLOCK;             // solid square block
    inline unsigned int board = ACS_BOARD;             // board of squares
    inline unsigned int bottom_tee = ACS_BTEE;         // bottom tee
    inline unsigned int bullet = ACS_BULLET;           // bullet
    inline unsigned int checker_board = ACS_CKBOARD;   // checker board
    inline unsigned int down_arrow = ACS_DARROW;       // arrow pointing down
    inline unsigned int degree = ACS_DEGREE;           // degree symbol
    inline unsigned int diamond = ACS_DIAMOND;         // diamond
    inline unsigned int ge_sign = ACS_GEQUAL;          // >=
    inline unsigned int hline = ACS_HLINE;             // horizontal line
    inline unsigned int lantern = ACS_LANTERN;         // lantern symbol
    inline unsigned int left_arrow = ACS_LARROW;       // arrow pointing left
    inline unsigned int le_sign = ACS_LEQUAL;          // less-than-or-equal-to
    inline unsigned int ll_corner = ACS_LLCORNER;      // lower left-hand corner
    inline unsigned int lr_corner = ACS_LRCORNER;      // lower right-hand corner
    inline unsigned int left_tee = ACS_LTEE;           // left tee
    inline unsigned int ne_sign = ACS_NEQUAL;          // not-equal
    inline unsigned int pi = ACS_PI;                   // greek pi
    inline unsigned int plus_minus = ACS_PLMINUS;      // plus/minus
    inline unsigned int plus = ACS_PLUS;               // plus
    inline unsigned int right_arrow = ACS_RARROW;      // arrow pointing right
    inline unsigned int right_tee = ACS_RTEE;          // right tee
    inline unsigned int scan_line_1 = ACS_S1;          // scan line 1
    inline unsigned int scan_line_3 = ACS_S3;          // scan line 3
    inline unsigned int scan_line_7 = ACS_S7;          // scan line 7
    inline unsigned int scan_line_9 = ACS_S9;          // scan line 9
    inline unsigned int sterling = ACS_STERLING;       // pound-sterling
    inline unsigned int top_tee = ACS_TTEE;            // top tee
    inline unsigned int up_arrow = ACS_UARROW;         // arrow pointing up
    inline unsigned int ul_corner = ACS_ULCORNER;      // upper left-hand corner
    inline unsigned int ur_corner = ACS_URCORNER;      // upper right-hand corner
    inline unsigned int vline = ACS_VLINE;             // vertical line
  };

  void initialize(bool one_char, bool no_echo, bool special_keys, 
                          bool use_color);

  void restore_terminal_settings();

  int read_input();

  void add_pixel_char(int x, int y, char pixel_type, Window* win_ptr = nullptr, 
                      char attribute = CharAttributes::normal);

};

#endif