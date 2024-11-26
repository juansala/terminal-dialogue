#ifndef STATE_HPP
#define STATE_HPP

class State
{
public:
  State() {}
  ~State() {}
};

class GameState : public State
{
public:
  GameState() {}
  ~GameState() {}
};

class MenuState : public State
{
public: 
  MenuState() {}
  ~MenuState() {}
};

#endif