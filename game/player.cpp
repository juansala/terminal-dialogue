#include "terminal_dialogue/game/player.hpp"

Player::Player(int x, int y, int move_speed)
: Entity{ x, y },
  m_move_speed{ move_speed } {}
  // m_geom{ std::make_shared<Rectangle>(x, y, 'x', 1, 1) }

void Player::Update() {
  // TODO(juansala): Move to a class Script or Controller
  unsigned int input = ncurses_wrapper::ReadInput();
  if (input != ncurses_wrapper::input_keys::kNone) {
    switch (input) {
      case ncurses_wrapper::input_keys::kUp:
        SetPosition(m_x, m_y - m_move_speed);
        break;
      case ncurses_wrapper::input_keys::kDown:
        SetPosition(m_x, m_y + m_move_speed);
        break;
      case ncurses_wrapper::input_keys::kLeft:
        SetPosition(m_x - m_move_speed, m_y);
        break;
      case ncurses_wrapper::input_keys::kRight:
        SetPosition(m_x + m_move_speed, m_y);
        break;
    }
  }
}

void Player::Draw() {
  Rectangle rect(m_x, m_y, 'X', 1, 1);
  rect.Draw();
  // m_geom->draw();
}
