#include "terminal_dialogue/game/entity.hpp"

Entity::Entity()
{
  m_name = "entity"; // TODO: Look into static local variables for counting?
  m_wpm = 200;
  m_color_pair = COLOR_PAIR(0);
  m_pause_time = 50;
}

Entity::Entity(std::string &name, int wpm, int color_pair, int pause_time) :
  // TODO: Add data member for language (for average char per word)
  m_name {name}, // TODO: Learn about std::string_view for better type to use.
  m_wpm {wpm},
  m_color_pair {color_pair}, // TODO: Init using RGB values.
  m_pause_time {pause_time}
{
}

void Entity::speak(WINDOW* win, int xy[], std::string &msg, bool print) const
{
  wmove(win, xy[0], xy[1]);
  
  if (!print)
  {
    DialogueState state = TALKING;
    int millis_per_c = 1 / (m_wpm * 4.5 * 1/6e4); // TODO: Use avg char/word from language.
    auto pause_start_time = std::chrono::high_resolution_clock::now(); // TODO: Replace definition w/ correct type.
    auto last_time = std::chrono::high_resolution_clock::now();
    auto current_time = std::chrono::high_resolution_clock::now();
    int i = 0;
    int dt = 0;

    while(i < msg.length())
    {
      if (state == PAUSE)
      {
        current_time = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - pause_start_time).count();
        if (dt > m_pause_time)
        {
          state = TALKING;
          i++;
        }
      }
      else if (state == TALKING)
      {
        if (msg[i] == '.' || msg[i] == '!' || msg[i] == '?' || msg[i] == ',')
        {
          state = PAUSE;      
          pause_start_time = std::chrono::high_resolution_clock::now();
          waddch(win, msg[i] | m_color_pair);
          wrefresh(win);
          continue;
        }

        auto current_time = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time).count();
        if (dt >= millis_per_c)
        {
          waddch(win, msg[i] | m_color_pair);
          wrefresh(win);
          last_time = std::chrono::high_resolution_clock::now();
          i++;
        }
      }
    }
  }
  else
  {
    for(int i = 0; i < msg.length(); i++)
    {
      waddch(win, msg[i] | m_color_pair);
      wrefresh(win);
    }
  }
}

