#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

#include "terminal_dialogue/graphics/rectangle.hpp"

class Renderer {
public:
  Renderer() {}
  ~Renderer() {}

  void Draw(std::vector<Geometry::SharedPtr>& frame);
};

#endif