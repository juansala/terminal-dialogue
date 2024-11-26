#include "terminal_dialogue/game/player.hpp"

Player::Player(int x, int y, int move_speed)
: Entity{ x, y },
  m_move_speed{ move_speed },
  m_geom{ std::make_shared<Rectangle>(x, y, 'x', 1, 1) } // TODO(juansala): Fix
{}

void Player::update()
{
  // TODO(juansala): Move to a class Script or Controller
  unsigned int input = ncurses_wrapper::read_input();
  if (input != ncurses_wrapper::InputKeys::NONE)
  {
    switch (input)
    {
      case ncurses_wrapper::InputKeys::RIGHT:
        set_position(m_x + m_move_speed, m_y);
        break;
      case ncurses_wrapper::InputKeys::LEFT:
        set_position(m_x + m_move_speed, m_y);
        break;
    }
  }
}

void Player::draw()
{
  m_geom->draw();
}
