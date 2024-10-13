# Add examples as executables
add_executable(dialogue_example dialogue_example.cpp)
add_executable(typing_example typing_example.cpp)

# Link examples against the terminal-dialogue library
target_link_libraries(dialogue_example dialogue)
target_link_libraries(typing_example dialogue)

