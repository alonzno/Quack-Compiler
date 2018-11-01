cmake_minimum_required(VERSION 3.10)
project(Scanner)
set(CMAKE_CXX_STANDARD 14)

find_library(REFLEX_LIB "libreflex.a" 
    PATHS "/home/faculty/michal/classes/cis461/RE-flex/lib/")
find_path(REFLEX_INCLUDE "reflex"
    PATHS "/home/faculty/michal/classes/cis461/RE-flex/include/")
find_program(REFLEX "reflex"
    PATHS "/home/faculty/michal/classes/cis461/RE-flex/bin/")
find_program(BISON "bison"
    PATHS "/home/faculty/michal/classes/cis461/RE-flex/bin/")


add_custom_command(
        OUTPUT lex.yy.cpp lex.yy.h
        COMMAND   reflex --bison-cc --bison-locations --header-file ${CMAKE_CURRENT_SOURCE_DIR}/quack.lxx
        DEPENDS quack.lxx quack.tab.hxx
)

add_custom_command(
       OUTPUT quack.tab.cxx quack.tab.hxx location.hh position.hh stack.hh
       COMMAND bison -r all -Wconflicts-sr -d ${CMAKE_CURRENT_SOURCE_DIR}/quack.yxx
       DEPENDS quack.yxx)

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${REFLEX_INCLUDE}
        "/home/faculty/michal/classes/cis461/RE-flex/include/"
)

add_executable(parser
        quack.tab.cxx lex.yy.cpp lex.yy.h
        parser.cpp AST.cpp AST.h Messages.h Messages.cpp )
if(FALSE)
add_executable(lexer
        lex_driver.cpp
        lex.yy.cpp lex.yy.h
        location.hh position.hh
        quack.tab.hxx
        ASTNode.cpp ASTNode.h Messages.h Messages.cpp
        names.h)
endif()

target_link_libraries(parser ${REFLEX_LIB})
#target_link_libraries(lexer ${REFLEX_LIB})
