# Add examples as executables
add_executable(dialogue_example dialogue_example.cpp)
add_executable(typing_example typing_example.cpp)
add_executable(rectangle_example rectangle_example.cpp)
add_executable(renderer_example renderer_example.cpp)
add_executable(animation_example animation_example.cpp)
add_executable(engine_example engine_example.cpp)

# Link examples against the terminal-dialogue library
target_link_libraries(dialogue_example game)
target_link_libraries(typing_example game)
target_link_libraries(rectangle_example graphics)
target_link_libraries(renderer_example graphics)
target_link_libraries(animation_example graphics)
target_link_libraries(engine_example core game graphics)

