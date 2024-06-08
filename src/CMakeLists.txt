add_library(dialogue entity.cpp)

target_include_directories(dialogue PUBLIC ${CMAKE_SOURCE_DIR}/inc)

target_link_libraries(dialogue -lncurses)
