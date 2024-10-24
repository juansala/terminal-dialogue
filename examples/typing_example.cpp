#include "terminal_dialogue/game/game.hpp"
#include "terminal_dialogue/game/player.hpp"

// Simple typing game which demonstrates how to implement a custom TypingGame 
// class and how to run the game.
// TODO(juansala): Implement a TypingGame class.

class TypingGame : public Game
{
public:
  TypingGame()
  {
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

  void run()
  {
    // TODO: Rename input and txt indexing variables for clarity!
    Entity stream;
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
  std::vector<std::string> m_txt;
};

int main(int argc, char* argv[])
{
  TypingGame typing_game;
  typing_game.run();
  return 0;
}