#include <iostream>
#include "termcolor.hpp"
#include <chrono>
#include <ncurses.h>
#include "dialog.h"

Entity::Entity(std::string &name, int wpm, int rgb[], int pause_time) :
    // TODO: Add data member for language (for average char per word)
    m_name {name}, // TODO: Learn about std::string_view for better type to use.
    m_wpm {wpm},
    m_rgb {rgb[0], rgb[1], rgb[2]}, // TODO: Find better way for init.
    m_pause_time {pause_time}
{
}

void Entity::set_color(int rgb[])
{
    for(int i=0; i<RGB_SIZE; i++)
    {
        m_rgb[i] = rgb[i];
    }
}

void Entity::speak(WINDOW* win, std::string &msg) const
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
                waddch(win, msg[i] | COLOR_PAIR(1));
                wrefresh(win);
                continue;
            }

            auto current_time = std::chrono::high_resolution_clock::now();
            dt = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time).count();
            if (dt >= millis_per_c)
            {
                waddch(win, msg[i] | COLOR_PAIR(1));
                wrefresh(win);
                last_time = std::chrono::high_resolution_clock::now();
                i++;
            }
        }
    }
    
    std::cout << std::endl;
}

