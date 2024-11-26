# Add core library source files
add_library(core engine.cpp)

# Add include directories
target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Link against pre-installed ncurses C++ library
target_link_libraries(core -lncurses)