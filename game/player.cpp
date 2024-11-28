#include "terminal_dialogue/game/player.hpp"

Player::Player(int x, int y, int move_speed)
: Entity{ x, y },
  m_move_speed{ move_speed }
  // m_geom{ std::make_shared<Rectangle>(x, y, 'x', 1, 1) }
{}

void Player::update()
{
  // TODO(juansala): Move to a class Script or Controller
  unsigned int input = ncurses_wrapper::read_input();
  if (input != ncurses_wrapper::InputKeys::NONE)
  {
    switch (input)
    {
      case ncurses_wrapper::InputKeys::UP:
        set_position(m_x, m_y - m_move_speed);
        break;
      case ncurses_wrapper::InputKeys::DOWN:
        set_position(m_x, m_y + m_move_speed);
        break;
      case ncurses_wrapper::InputKeys::LEFT:
        set_position(m_x - m_move_speed, m_y);
        break;
      case ncurses_wrapper::InputKeys::RIGHT:
        set_position(m_x + m_move_speed, m_y);
        break;
    }
  }
}

void Player::draw()
{
  Rectangle rect(m_x, m_y, 'X', 1, 1);
  rect.draw();
  // m_geom->draw();
}
