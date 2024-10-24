#include "terminal_dialogue/game/game.hpp"

Game::Game() :
    m_num_entities{0},
    m_state{INIT},
    m_cursor_x{0},
    m_cursor_y{0},
    m_score{0}
{
  // TODO: See which of these actually need to be in this base class?
  initscr();
  noecho();
  cbreak();
  nodelay(stdscr, true);
  refresh();
  start_color();
  use_default_colors();

  // TODO: Move these implementation-specifics to derived classes.
  init_pair(1, 6, -1); // Cyan
  init_pair(2, 1, -1); // Red

  // std::cout << m_txt.size() << std::endl;

  m_state = GAME_CONTROL;
}
