#include <iostream>
#include "dialog.h"

int main(int argc, char* argv[])
{
    int red[3] = {255, 0, 0};
    std::string e1_name = "Entity 1";
    Entity e1{e1_name, 300, red};
    std::string e1_msg = "I am alive! This is the first test of terminal dialog's core functionality! I need to keep speaking in exclamations in order to demonstrate it's functionality! Bye.";
    e1.speak(e1_msg);
    return 0;
}