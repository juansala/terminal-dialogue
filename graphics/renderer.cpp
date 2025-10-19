#include "terminal_dialogue/graphics/renderer.hpp"

void Renderer::Draw(std::vector<Geometry::SharedPtr>& frame) {
  for (Geometry::SharedPtr e : frame) {
    e->Draw();
  }
}