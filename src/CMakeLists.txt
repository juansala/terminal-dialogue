# Add core library source files
add_library(dialogue game.cpp entity.cpp player.cpp)

# Add include directories
target_include_directories(dialogue PUBLIC ${CMAKE_SOURCE_DIR}/inc)

# Link against pre-installed ncurses C++ library
target_link_libraries(dialogue -lncurses)