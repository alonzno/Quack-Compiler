cmake_minimum_required(VERSION 3.10)
project(Scanner)
set(CMAKE_CXX_STANDARD 14)


find_library(REFLEX_LIB "libreflex.a" 
    PATHS "/home/faculty/michal/classes/cis461/RE-flex/lib/")
find_path(REFLEX_INCLUDE "reflex"
    PATHS "/home/faculty/michal/classes/cis461/RE-flex/include/")
find_program(REFLEX "reflex"
    PATHS "/home/faculty/michal/classes/cis461/RE-flex/bin/")
add_custom_command(
        OUTPUT lex.yy.cpp
        COMMAND   ${REFLEX} ${CMAKE_CURRENT_SOURCE_DIR}/lexerspec.l
        DEPENDS lexerspec.l 
)

include_directories(
        ${REFLEX_INCLUDE}
)

add_executable(scanner lex.yy.cpp)

target_link_libraries(scanner ${REFLEX_LIB})
