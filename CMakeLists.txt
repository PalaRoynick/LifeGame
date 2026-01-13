cmake_minimum_required(VERSION 3.20)
project(lifegame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cxx
    cell.cxx
    cell_board.cxx
    state_machine.cxx
)

add_executable(run ${SOURCES})
