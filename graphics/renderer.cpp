#include "terminal_dialogue/graphics/renderer.hpp"

void Renderer::draw(std::vector<Geometry::SharedPtr>& frame)
{
  for (Geometry::SharedPtr e : frame)
  {
    e->draw();
  }
}