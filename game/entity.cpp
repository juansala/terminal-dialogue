#include "terminal_dialogue/game/entity.hpp"

Entity::Entity(int x, int y)
: m_x{x},
  m_y{y},
  m_is_active{true} {
  m_id = 0;
}

void Entity::SetPosition(int x, int y) {
  m_x = x;
  m_y = y;
}

void Entity::GetPosition(int& x, int& y) {
  x = m_x;
  y = m_y;
}