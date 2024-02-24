
cmake_minimum_required(VERSION 3.10)

project(sctimer)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(sctimer src/main.c src/timer.c)
target_link_libraries(sctimer ${CURSES_LIBRARIES})
