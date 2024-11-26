#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <array>
#include <vector>

#include "terminal_dialogue/game/entity.hpp"

class EntityManager
{
public:
  EntityManager() {}
  ~EntityManager() {}

  void update();
  void draw();

  // TODO(juansala): Adds the entity in the next update.
  void add_entity(Entity::SharedPtr entity) {}
  void add_entities(std::vector<Entity::SharedPtr>& entities) {}
  
  // Removes the entity identified with `id` in the next update.
  // void kill_entity(int id);
  // void kill_entities(std::vector<int>& ids);

private:
  std::vector<Entity::SharedPtr> m_entities;
};

#endif