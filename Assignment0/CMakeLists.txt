cmake_minimum_required(VERSION 3.12)
project(Scanner)
set(CMAKE_CXX_STANDARD 14)


find_library(REFLEX_LIB "libreflex.a")
find_path(REFLEX_INCLUDE "reflex")

add_custom_command(
        OUTPUT lex.yy.cpp
        COMMAND   reflex ${CMAKE_CURRENT_SOURCE_DIR}/lexerspec.l
        DEPENDS lexerspec.l 
)

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${REFLEX_INCLUDE}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(scanner lex.yy.cpp)

target_link_libraries(scanner ${REFLEX_LIB})
