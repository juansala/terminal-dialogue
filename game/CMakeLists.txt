# Add core library source files
add_library(game game.cpp entity.cpp player.cpp)

# Add include directories
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Link against pre-installed ncurses C++ library
target_link_libraries(game -lncurses)