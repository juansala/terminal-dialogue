#include <vector>
#include "entity.h"
/*

TODO:
- Add entities through member function.
*/
class Game
{
public:
    Game();
    
    enum GameState
    {
        INIT,
        MAIN_MENU,
        PLAYER_CONTROL,
        GAME_CONTROL,
        PAUSE,
        EXIT
    };

    void run();
    // void update_state();

private:
    int m_num_entities; // Count number of entities.
    GameState m_state;
    std::vector<std::string> m_txt;
};