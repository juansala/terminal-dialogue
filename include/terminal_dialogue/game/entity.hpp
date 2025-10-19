#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <cstddef>
#include <chrono>
#include <memory>

#include "terminal_dialogue/graphics/geometry.hpp"

class Entity {
public:
  using SharedPtr = std::shared_ptr<Entity>;
  Entity(int x = 0, int y = 0);
  ~Entity() {}

  virtual void Update() {};
  virtual void Draw() {};

  void SetPosition(int x, int y);
  void GetPosition(int& x, int& y);

protected:
  int m_x;
  int m_y;
  std::size_t m_id;
  bool m_is_active;
};

#endif