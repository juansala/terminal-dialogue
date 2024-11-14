#include "terminal_dialogue/graphics/frame.hpp"

Frame::Frame(std::vector<Geometry::SharedPtr>& elements)
: m_elements{ elements },
  m_num_elements{ elements.size() }
{}

void Frame::draw()
{
  for (Geometry::SharedPtr e : m_elements)
  {
    e->draw();
  }
}