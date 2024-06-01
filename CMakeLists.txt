cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(terminal_dialogue VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add dialogue library
add_library(dialogue dialog.cpp)
target_include_directories(dialogue PUBLIC ${CMAKE_SOURCE_DIR})

# Add the executable
add_executable(terminal_dialogue demo.cpp)

# Link the dialogue library
target_link_libraries(terminal_dialogue dialogue)