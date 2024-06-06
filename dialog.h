#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <ncurses.h>

class Entity
{
private:
    std::string m_name; // Entity name
    int m_wpm; // dialog speed, in wpm
    int m_rgb[3]; // RGB color for text
    const int RGB_SIZE{3}; // TODO: Initialize in constructor?
    int m_pause_time; // pause duration, in ms

public:
    Entity(std::string &name, int wpm, int rgb[], int pause_time);

    std::string name() {return m_name;};
    void set_speed(int wpm) {m_wpm = wpm;};
    void set_color(int rgb[3]);
    void set_pause_time(int pause_time) {m_pause_time = pause_time;};
    void speak(WINDOW* win, std::string &msg) const;

    enum DialogueState
    {
        TALKING,
        PAUSE
    };
};

#endif