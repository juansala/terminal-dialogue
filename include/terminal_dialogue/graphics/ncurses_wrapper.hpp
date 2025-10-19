#ifndef NCURSES_WRAPPER_HPP
#define NCURSES_WRAPPER_HPP

#include <array>
#include <memory>

#include <ncurses.h>

// This file is meant to lay a newer, easier interface for drawing graphics in
// a text-based terminal using ncurses under the hood. It is meant to hide away
// the interface established by ncurses. To learn about the actual ncurses
// interface, please refer to online resources (e.g. Ncurses Programming Guide
// by J.B. Wyatt) or check out the library source code.

// Is graphics something that should eventually be handled by the GPU? I would
// guess that's not necessary (perhaps impossible) given it's literally text.

// TODO(juansala): Auto-select this square font: https://strlen.com/square/
// TODO(juansala): Redefine functions using outdated types (e.g. short).
// TODO(juansala): Switch to std::array for best modern practice (constexpr).
// TODO(juansala): Add multiple windows.

namespace ncurses_wrapper {
  using Window = WINDOW;
  using WindowSharedPtr = std::shared_ptr<Window>;

  struct Color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    size_t id;
  };

  namespace default_colors {
    constexpr Color kBlack = {255, 255, 255, 0};
    constexpr Color kRed = {255, 0, 0, 1};
    constexpr Color kGreen = {0, 255, 0, 2};
    constexpr Color kYellow = {255, 255, 0, 3};
    constexpr Color kBlue = {0, 0, 255, 4};
    constexpr Color kMagenta = {255, 0, 255, 5};
    constexpr Color kCyan = {0, 255, 255, 6};
    constexpr Color kWhite = {0, 0, 0, 7};
  };

  struct ColorPair {
    Color foreground;
    Color background;
    size_t id;
  };

  namespace default_color_pairs {
    constexpr ColorPair kClassic = {default_colors::kWhite,
                                    default_colors::kBlack, 0};
    constexpr ColorPair kClassicRed = {default_colors::kRed,
                                       default_colors::kBlack, 1};
    constexpr ColorPair kClassicBlue = {default_colors::kBlue,
                                        default_colors::kBlack, 2};
    constexpr ColorPair kClassicGreen = {default_colors::kGreen,
                                         default_colors::kBlack, 3};
    constexpr size_t kNPairs = 4;
    static constexpr std::array<ColorPair, kNPairs> kPairs = {kClassic,
                                                              kClassicRed,
                                                              kClassicBlue,
                                                              kClassicGreen};
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

  namespace char_attributes {
    // TODO(juansala): Check type conversions.
    constexpr unsigned int kNormal = A_NORMAL;             // Normal display
    constexpr unsigned int kHighlight = A_STANDOUT;        // Highlighting
    constexpr unsigned int kUnderline = A_UNDERLINE;       // Underlining
    constexpr unsigned int kReverseVideo = A_REVERSE;     // Reverse video
    constexpr unsigned int kBlinking = A_BLINK;            // Blinking
    constexpr unsigned int kDim = A_DIM;                   // Half bright
    constexpr unsigned int kBold = A_BOLD;                 // Bold
    constexpr unsigned int kProtect = A_PROTECT;           // Protected mode
    constexpr unsigned int kInvisible = A_INVIS;           // Invisible mode
    constexpr unsigned int kAltCharSet = A_ALTCHARSET;   // Alternate char set
    constexpr unsigned int kExtract = A_CHARTEXT;          // Bit-mask to extract a character
  };

  // TODO(juansala): Special chars not displaying properly. Check locale.
  namespace special_chars {
    inline const unsigned int kBlock = ACS_BLOCK;             // solid square block
    inline const unsigned int kBoard = ACS_BOARD;             // board of squares
    inline const unsigned int kBottomTee = ACS_BTEE;         // bottom tee
    inline const unsigned int kBullet = ACS_BULLET;           // bullet
    inline const unsigned int kCheckerBoard = ACS_CKBOARD;   // checker board
    inline const unsigned int kDownArrow = ACS_DARROW;       // arrow pointing down
    inline const unsigned int kDegree = ACS_DEGREE;           // degree symbol
    inline const unsigned int kDiamond = ACS_DIAMOND;         // diamond
    inline const unsigned int kGreaterThanOrEqual = ACS_GEQUAL;          // >=
    inline const unsigned int kHLine = ACS_HLINE;             // horizontal line
    inline const unsigned int kLantern = ACS_LANTERN;         // lantern symbol
    inline const unsigned int kLeftArrow = ACS_LARROW;       // arrow pointing left
    inline const unsigned int kLessThanOrEqual = ACS_LEQUAL;          // less-than-or-equal-to
    inline const unsigned int kLowerLeftCorner = ACS_LLCORNER;      // lower left-hand corner
    inline const unsigned int kLowerRightCorner = ACS_LRCORNER;      // lower right-hand corner
    inline const unsigned int kLeftTee = ACS_LTEE;           // left tee
    inline const unsigned int kNotEqual = ACS_NEQUAL;          // not-equal
    inline const unsigned int kPi = ACS_PI;                   // greek pi
    inline const unsigned int kPlusMinus = ACS_PLMINUS;      // plus/minus
    inline const unsigned int kPlus = ACS_PLUS;               // plus
    inline const unsigned int kRightArrow = ACS_RARROW;      // arrow pointing right
    inline const unsigned int kRightTee = ACS_RTEE;          // right tee
    inline const unsigned int kScanLine_1 = ACS_S1;          // scan line 1
    inline const unsigned int kScanLine_3 = ACS_S3;          // scan line 3
    inline const unsigned int kScanLine_7 = ACS_S7;          // scan line 7
    inline const unsigned int kScanLine_9 = ACS_S9;          // scan line 9
    inline const unsigned int kSterling = ACS_STERLING;       // pound-sterling
    inline const unsigned int kTopTee = ACS_TTEE;            // top tee
    inline const unsigned int kUpArrow = ACS_UARROW;         // arrow pointing up
    inline const unsigned int kUpperLeftCorner = ACS_ULCORNER;      // upper left-hand corner
    inline const unsigned int kUpperRightCorner = ACS_URCORNER;      // upper right-hand corner
    inline const unsigned int kVLine = ACS_VLINE;             // vertical line
  };

  namespace input_keys {
    constexpr unsigned int kNone = ERR;
    constexpr unsigned int kUp = KEY_UP;
    constexpr unsigned int kLeft = KEY_LEFT;
    constexpr unsigned int kRight = KEY_RIGHT;
    constexpr unsigned int kDown = KEY_DOWN;
    constexpr unsigned int kSpace = ' ';
  }

  void Initialize(bool one_char, bool no_echo, bool special_keys, 
                  bool use_color, bool no_delay=true);

  void InitializePairs();

  // void parse_color_file();

  void WindowRefresh(WindowSharedPtr win_ptr = nullptr);

  void WindowClear(WindowSharedPtr win_ptr = nullptr);

  void RestoreTerminalSettings();

  int ReadInput();

  void AddPixelChar(int x, int y, unsigned int pixel_type,
                    ColorPair color_pair, WindowSharedPtr win_ptr = nullptr,
                    unsigned int attribute = char_attributes::kNormal);

};

#endif