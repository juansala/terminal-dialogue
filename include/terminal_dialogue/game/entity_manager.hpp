#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <array>
#include <vector>

#include "terminal_dialogue/game/entity.hpp"

class EntityManager {
public:
  EntityManager() {}
  ~EntityManager() {}

  void Update();
  void Draw();

  // TODO(juansala): Adds the entity in the next update.
  void AddEntity(Entity::SharedPtr entity);
  void AddEntities(std::vector<Entity::SharedPtr>& entities) {}
  
  // Removes the entity identified with `id` in the next update.
  // void KillEntity(int id);
  // void KillEntities(std::vector<int>& ids);

private:
  std::vector<Entity::SharedPtr> m_entities;
};

#endif