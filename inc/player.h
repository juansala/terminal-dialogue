#include <iostream>
#include "entity.h"

class Player: public Entity
{
private:
    int m_player_id; // TODO: Define player id using static local vars?
public:
    Player();
    int get_id() const {return m_player_id;};
};