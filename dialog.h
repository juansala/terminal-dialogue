#ifndef DIALOG_H
#define DIALOG_H

#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_name;
    int m_wpm; // dialog speed, in wpm
    int m_rgb[3]; // RGB color for text
    const int RGB_SIZE = 3; // TODO: Initialize in constructor?
public:
    Entity(std::string &name, int wpm, int rgb[]);

    std::string name() {return m_name;};
    void set_speed(int wpm) {m_wpm = wpm;};
    void set_color(int rgb[3]);
    void speak(std::string &msg) const;
};

#endif