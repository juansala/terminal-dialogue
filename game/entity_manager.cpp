#include "terminal_dialogue/game/entity_manager.hpp"

void EntityManager::Update() {
  for (auto e : m_entities) {
    e->Update();
  }

  Draw();
}

void EntityManager::Draw() {
  for (auto e : m_entities) {
    e->Draw();
  }
}

void EntityManager::AddEntity(Entity::SharedPtr entity) {
  m_entities.push_back(entity);
}