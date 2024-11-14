# Add examples as executables
add_executable(dialogue_example dialogue_example.cpp)
add_executable(typing_example typing_example.cpp)
add_executable(rectangle_example rectangle_example.cpp)
add_executable(frame_example frame_example.cpp)

# Link examples against the terminal-dialogue library
target_link_libraries(dialogue_example game)
target_link_libraries(typing_example game)
target_link_libraries(rectangle_example graphics)
target_link_libraries(frame_example graphics)

