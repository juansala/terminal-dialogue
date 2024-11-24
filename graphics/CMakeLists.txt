# Add core library source files
add_library(graphics 
            rectangle.cpp 
            geometry.cpp 
            renderer.cpp 
            ncurses_wrapper.cpp)

# Add include directories
target_include_directories(graphics PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Link against pre-installed ncurses C++ library
target_link_libraries(graphics -lncurses)