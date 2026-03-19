cmake_minimum_required(VERSION 3.16)
project(elite_parser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    elite_parser
    src/main.cpp
    src/first_follow.cpp
    src/grammar.cpp
    src/grammar_io.cpp
    src/left_recursion.cpp
    src/parser.cpp
    src/parsing_table.cpp
)

target_include_directories(elite_parser PRIVATE include)

if(MSVC)
    target_compile_options(elite_parser PRIVATE /W4 /permissive-)
else()
    target_compile_options(elite_parser PRIVATE -Wall -Wextra -pedantic)
endif()
