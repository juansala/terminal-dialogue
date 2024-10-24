#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "terminal_dialogue/game/entity.h"

class Player: public Entity
{
private:
  int m_player_id;
  int m_score;
public:
  Player();

  void add_pts(int reward) { m_score += reward; }
  void sub_pts(int penalty) { m_score += penalty; }
  int get_score() { return m_score; };
};

#endif