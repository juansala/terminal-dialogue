# terminal-dialogue

A small C++ library (with examples) for creating simple games in a Linux terminal using the ```ncurses``` library.

Tested on Ubuntu 22.04 (WSL).

## Dependencies
- libncurses5-dev
- libncursesw5-dev
- CMake >= 3.10

## Try Examples
- Clone this repo somewhere on your Linux machine: ```git clone https://github.com/juansala/terminal-dialogue.git```
- ```cd terminal-dialogue && mkdir build```
- ```cd build && cmake ..```
- ```cmake --build .```

## Import into a CMake project
Fetch ```terminal-dialogue``` from source for your project using the template CMakeLists file.

TODO(juansala): Add example CMakeLists.txt that uses ExternalProject to fetch library from source.