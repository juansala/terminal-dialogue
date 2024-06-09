add_library(dialogue game.cpp entity.cpp player.cpp)

target_include_directories(dialogue PUBLIC ${CMAKE_SOURCE_DIR}/inc)

target_link_libraries(dialogue -lncurses)
