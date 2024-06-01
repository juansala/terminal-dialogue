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
    DialogueState state = TALKING;
    int millis_per_c = 1 / (m_wpm * 4.5 * 1/6e4); // TODO: Use avg char/word from language.
    int pause_millis = 500; // TODO: Use data member.
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
            if (dt > pause_millis)
            {
                state = TALKING;
                i++;
            }
        }
        else if (state == TALKING)
        {
            auto current_time = std::chrono::high_resolution_clock::now();
            dt = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time).count();
            if (dt >= millis_per_c)
            {
                // TODO: What does std::flush do exactly?
                // const int r = 0;
                // const int g = 0;
                // const int b = 0;
                std::cout << termcolor::red << msg[i] << std::flush; // TODO: Color.
                last_time = std::chrono::high_resolution_clock::now();
                i++;
            }

            if (msg[i] == '.' || msg[i] == '!' || msg[i] == '?') // TODO: Check for one of these: .?!,(...)
            {
                state = PAUSE;      
                pause_start_time = std::chrono::high_resolution_clock::now();
                std::cout << termcolor::red << msg[i] << std::flush;
            }
        }
    }
    
    std::cout << std::endl;
}

