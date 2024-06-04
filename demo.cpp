#include <iostream>
#include "dialog.h"

int main(int argc, char* argv[])
{
    int red[3] = {255, 0, 0};
    std::string e1_name = "Entity 1";
    Entity e1{e1_name, 300, red, 500};
    std::string e1_msg = "I am alive! Check me out! I am ... pausing, almost whenever I want. What do you think?";
    e1.speak(e1_msg);
    return 0;
}