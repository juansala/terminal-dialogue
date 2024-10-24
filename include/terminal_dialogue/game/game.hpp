#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <chrono>

#include <ncurses.h>

#include "terminal_dialogue/game/entity.hpp"
/*
TODO:
- Add entities through member function.
*/
class Game
{
public:
  Game();
  
  enum GameState // TODO: Move into a separate header file?
  {
    INIT,
    MAIN_MENU,
    PLAYER_CONTROL,
    GAME_CONTROL,
    PAUSE,
    EXIT
  };

  void run();
  // void update_state();

protected:
  int m_num_entities; // Count number of entities.
  int m_score;
  GameState m_state;
  int m_cursor_x;
  int m_cursor_y;
};

#endif