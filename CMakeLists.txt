cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(terminal_dialogue VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add examples subdirectory
add_subdirectory(examples)

# Add game subdirectory
add_subdirectory(game)

# Add graphics subdirectroy
add_subdirectory(graphics)