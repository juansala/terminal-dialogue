#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "terminal_dialogue/game/entity.hpp"
#include "terminal_dialogue/graphics/rectangle.hpp"

class Player : public Entity
{
public:
  using SharedPtr = std::shared_ptr<Player>;
  Player() {}
  Player(int x, int y, int move_speed = 1);
  ~Player() {};

  virtual void update() override;
  virtual void draw() override;

protected:
  // Characteristics, score, buffs/debuffs, etc are protected attributes
  // Geometry::SharedPtr m_geom;
  int m_move_speed;
};

#endif