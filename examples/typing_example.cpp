#include <chrono>
#include <string>
#include <vector>

#include <ncurses.h>

// Simple typing game which demonstrates how to implement a custom TypingGame 
// class and how to run the game.
// TODO(juansala): Implement a TypingGame class.

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

class TypingGame
{
public:
  TypingGame()
  : m_num_entities{0},
    m_state{INIT},
    m_cursor_x{0},
    m_cursor_y{0},
    m_score{0}
  {
    // TODO: See which of these actually need to be in this base class?
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, true);
    refresh();
    start_color();
    use_default_colors();

    // TODO: Move these implementation-specifics to derived classes.
    init_pair(1, 6, -1); // Cyan
    init_pair(2, 1, -1); // Red

    // std::cout << m_txt.size() << std::endl;

    m_state = GAME_CONTROL;

    init_pair(1, 6, -1); // Cyan
    init_pair(2, 1, -1); // Red

    m_txt = 
    {
      "This is test 1.",
      "This is test 2.",
      "This is test 3.",
      "This is test 4.",
      "This is test 5."
    };
  }

  enum GameState // TODO: Move into a separate header file?
  {
    INIT,
    MAIN_MENU,
    PLAYER_CONTROL,
    GAME_CONTROL,
    PAUSE,
    EXIT
  };

  void run()
  {
    // TODO: Rename input and txt indexing variables for clarity!
    DialogueEntity stream;
    stream.set_color(COLOR_PAIR(1));
    char ch{0};
    int input_idx = 0;
    int line_pos[2] = {0, 0};
    int txt_idx = 0;
    auto start_time = std::chrono::high_resolution_clock::now();
    auto current_time = std::chrono::high_resolution_clock::now();
    std::string score_msg = "";
    while (m_state != EXIT)
    {
      if (m_state == GAME_CONTROL)
      {
        if (txt_idx == m_txt.size()) 
        {
          m_state = EXIT;
          continue;
        }
        stream.speak(stdscr, line_pos, m_txt[txt_idx], true);
        move(line_pos[0], line_pos[1]); // TODO: Use member function.
        m_state = PLAYER_CONTROL;
        start_time = std::chrono::high_resolution_clock::now();
      }
      else if (m_state == PLAYER_CONTROL)
      {
        int txt_length = m_txt[txt_idx].length();
        if (input_idx == txt_length)
        {
          current_time = std::chrono::high_resolution_clock::now();
          float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
          m_score = (txt_length / elapsed);
          m_state = GAME_CONTROL;
          input_idx = 0;
          txt_idx++;
          move(line_pos[0], line_pos[1]);
          score_msg = "Score: " + std::to_string(m_score);
          stream.speak(stdscr, line_pos, score_msg, true);
          continue;
        }
        else if ((ch = getch()) != ERR)
        {
          if (ch != m_txt[txt_idx][input_idx])
          {
            getyx(stdscr, m_cursor_y, m_cursor_x);
            addch(m_txt[txt_idx][input_idx] | COLOR_PAIR(2));
            move(m_cursor_y, m_cursor_x);
            continue;
          }

          addch(ch | COLOR_PAIR(1));
          input_idx++;
        }
      }
    }
    endwin();
  }

private:
  int m_num_entities; // Count number of entities.
  int m_score;
  GameState m_state;
  int m_cursor_x;
  int m_cursor_y;
  std::vector<std::string> m_txt;
};

int main(int argc, char* argv[])
{
  TypingGame typing_game;
  typing_game.run();
  return 0;
}