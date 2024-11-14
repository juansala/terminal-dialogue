#ifndef TEXT_HPP
#define TEXT_HPP

#include "terminal_dialogue/graphics/ncurses_wrapper.hpp"

// This file declares text-relevant classes used for stylizing or animating
// string-based messages such as menu options, dialogue, etc.
// TODO(juansala): Implement animated dialogue.

class Text
{
public:
  Text() {};
  ~Text() {};
};

class AnimatedText : public Text
{
public:
  AnimatedText() {};
  ~AnimatedText() {};
};

#endif