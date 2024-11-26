#include <chrono>
#include <string>

#include <ncurses.h>

// Simple example which demonstrates simple animated dialogue text using the
// DialogueEntity class.
// TODO(juansala): Wrap the common ncurses function calls into a convenient
// function or class (maybe ScreenManager?).

class DialogueEntity
{
public:
  DialogueEntity()
  {
    m_name = "entity"; // TODO: Look into static local variables for counting?
    m_wpm = 200;
    m_color_pair = COLOR_PAIR(0);
    m_pause_time = 50;
  }

  DialogueEntity(std::string &name, int wpm, int color_pair, int pause_time)
  : m_name {name}, // TODO: Learn about std::string_view for better type to use.
    m_wpm {wpm},
    m_color_pair {color_pair}, // TODO: Init using RGB values.
    m_pause_time {pause_time}
  {}

  std::string name() { return m_name; }
  void set_speed(int wpm) { m_wpm = wpm; }
  void set_color(int color_pair) { m_color_pair = color_pair; }
  void set_pause_time(int pause_time) { m_pause_time = pause_time; }

  void speak(WINDOW* win, int xy[], std::string &msg, bool print) const
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

  enum DialogueState
  {
    TALKING,
    PAUSE
  };

private:
  std::string m_name; // Entity name
  int m_wpm; // dialog speed, in wpm
  int m_color_pair; // ncurses color pair number
  const int RGB_SIZE{3}; // TODO: Initialize in constructor?
  int m_pause_time; // pause duration, in ms
};

int main(int argc, char* argv[])
{
  initscr();
  noecho();
  cbreak();
  refresh();

  start_color();
  use_default_colors();
  init_pair(1, 6, -1);

  int red = COLOR_PAIR(1);
  std::string e1_name = "Entity 1";
  DialogueEntity e1{e1_name, 300, red, 500};
  std::string e1_msg = "I am alive! Check me out! I am ... pausing, almost whenever I want. What do you think?";
  int xy[2] {0, 0};
  e1.speak(stdscr, xy, e1_msg, false);

  std::string return_msg = "Press any key to continue...";
  e1.set_color(COLOR_PAIR(0));
  int new_loc[2] {5, 0};
  e1.speak(stdscr, new_loc, return_msg, true);
  getch();
  endwin();
  return 0;
}