#include <chrono>
#include "dialog.h"
#include "termcolor.hpp"

Entity::Entity(std::string &name, int wpm, int rgb[]) :
    // TODO: Add data member for language (for average char per word)
    m_name {name}, // TODO: Learn about std::string_view for better type to use.
    m_wpm {wpm},
    m_rgb {rgb[0], rgb[1], rgb[2]} // TODO: Find better way for init.
{
    std::cout << "Created entity " << name << "." << std::endl;
}

void Entity::set_color(int rgb[])
{
    for(int i=0; i<RGB_SIZE; i++)
    {
        m_rgb[i] = rgb[i];
    }
}

void Entity::speak(std::string &msg) const
{
    // std::cout << msg << std::endl;
    // TODO: Switch to FSM using an enum.
    int millis_per_c = 1 / (m_wpm * 4.5 * 1/6e4); // TODO: Use avg char/word from language.
    int pause_millis = 1000; // TODO: Use data member.
    auto pause_start_time = std::chrono::high_resolution_clock::now(); // TODO: Replace definition w/ correct type.
    auto last_time = std::chrono::high_resolution_clock::now();
    auto current_time = std::chrono::high_resolution_clock::now();
    int i = 0;
    int dt = 0;
    bool pause = false;
    while(i < msg.length())
    {
        if (msg[i] == '!' && !pause) // TODO: Check for one of these: .?!,(...)
        {
            pause = true;
            pause_start_time = std::chrono::high_resolution_clock::now();
            std::cout << termcolor::red << msg[i] << std::flush;
        }

        if (pause)
        {
            current_time = std::chrono::high_resolution_clock::now();
            dt = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - pause_start_time).count();
            if (dt > pause_millis)
            {
                pause = false;
                i++;
            }
        }
        else
        {
            auto current_time = std::chrono::high_resolution_clock::now();
            dt = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time).count();
            if (dt >= millis_per_c)
            {
                // TODO: What does std::flush do exactly?
                std::cout << termcolor::red << msg[i] << std::flush; // TODO: Color.
                last_time = std::chrono::high_resolution_clock::now();
                i++;
            }
        }
    }
    
    std::cout << std::endl;
}

