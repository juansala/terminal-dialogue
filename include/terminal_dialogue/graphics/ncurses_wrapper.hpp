#ifndef NCURSES_WRAPPER_HPP
#define NCURSES_WRAPPER_HPP

#include <ncurses.h>

// This file is meant to lay a newer, easier interface for drawing graphics in
// a text-based terminal using ncurses under the hood. It is meant to hide away
// the interface established by ncurses. To learn about the actual ncurses
// interface, please refer to online resources (e.g. Ncurses Programming Guide
// by J.B. Wyatt) or check out the library source code.

// Is graphics something that should eventually be handled by the GPU? I would
// guess that's not necessary (perhaps impossible) given it's literally text.

// TODO(juansala): Convert raw pointers to smart pointers.
// TODO(juansala): Auto-select this square font: https://strlen.com/square/
// TODO(juansala): Redefine functions using outdated types (e.g. short).
// TODO(juansala): Switch to std::array for best modern practice (constexpr).
// TODO(juansala): Add multiple windows.

using Window = WINDOW;

namespace ncurses_wrapper
{
  struct Color
  {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    size_t id;
  };

  struct DefaultColors
  {
    static constexpr Color BLACK = {255, 255, 255, 0};
    static constexpr Color RED = {255, 0, 0, 1};
    static constexpr Color GREEN = {0, 255, 0, 2};
    static constexpr Color YELLOW = {255, 255, 0, 3};
    static constexpr Color BLUE = {0, 0, 255, 4};
    static constexpr Color MAGENTA = {255, 0, 255, 5};
    static constexpr Color CYAN = {0, 255, 255, 6};
    static constexpr Color WHITE = {0, 0, 0, 7};
  };

  struct ColorPair
  {
    Color foreground;
    Color background;
    size_t id;
  };

  struct DefaultColorPairs
  {
    static constexpr ColorPair CLASSIC = {DefaultColors::WHITE, 
                                          DefaultColors::BLACK, 0};
    static constexpr ColorPair CLASSIC_RED = {DefaultColors::RED,
                                              DefaultColors::BLACK, 1};
    static constexpr ColorPair CLASSIC_BLUE = {DefaultColors::BLUE,
                                               DefaultColors::BLACK, 2};
    static constexpr ColorPair CLASSIC_GREEN = {DefaultColors::GREEN,
                                                DefaultColors::BLACK, 3};
    static const size_t n_pairs = 4;
    static constexpr ColorPair pairs[n_pairs] = {CLASSIC,
                                                 CLASSIC_RED,
                                                 CLASSIC_BLUE,
                                                 CLASSIC_GREEN};
  };

  // TODO(juansala): Track imported colors using an array or map. Keys could be
  // strings defined by user in a config file.
  // struct ColorConfig
  // {
    // static const size_t NUM_COLORS = 256;
    // static const size_t NUM_COLOR_PAIRS = 256;
    // static const Color colors[NUM_COLORS];
    // static const ColorPair color_pairs[NUM_COLOR_PAIRS];
  // };

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

  namespace InputKeys
  {
    inline const unsigned int NONE = ERR;
    inline const unsigned int UP = KEY_UP;
    inline const unsigned int LEFT = KEY_LEFT;
    inline const unsigned int RIGHT = KEY_RIGHT;
    inline const unsigned int DOWN = KEY_DOWN;
    inline const unsigned int SPACE = ' ';
  }

  void initialize(bool one_char, bool no_echo, bool special_keys, 
                  bool use_color, bool no_delay=true);

  void initialize_pairs();

  // void parse_color_file();

  void window_refresh(Window* win_ptr = nullptr);

  void window_clear(Window* win_ptr = nullptr);

  void restore_terminal_settings();

  int read_input();

  void add_pixel_char(int x, int y, unsigned int pixel_type, 
                      ColorPair color_pair, Window* win_ptr = nullptr,
                      unsigned int attribute = CharAttributes::normal);

};

#endif