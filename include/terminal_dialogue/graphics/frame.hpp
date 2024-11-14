#ifndef FRAME_HPP
#define FRAME_HPP

#include <vector>

#include "terminal_dialogue/graphics/shape.hpp"
#include "terminal_dialogue/graphics/rectangle.hpp"

// TODO(juansala): Implement a Frame class that can contain a number of
// graphical elements and draw them all at once (e.g. publish).
// TODO(juansala): Figure out if this needs a resfresh function.
class Frame
{
public:
  Frame(std::vector<Geometry::SharedPtr>& elements);
  ~Frame() {}

  void draw();
private:
  std::vector<Geometry::SharedPtr> m_elements; 
  size_t m_num_elements;
};

#endif