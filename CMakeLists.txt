project(memeory_management)
cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR})

add_compile_options(-c
                    -Wall
                    -Wextra
                    -Winit-self
                    -Wold-style-cast
                    -Woverloaded-virtual
                    -Wuninitialized
                    -pedantic
                    -pedantic-errors
                    -std=c++1y
                    -g)

add_executable(valgrind1 valgrind1.cpp)
add_executable(valgrind2 valgrind2.cpp)
add_executable(valgrind3 valgrind3.cpp)
add_executable(list list.cpp)
add_executable(unique_ptr_solution unique_ptr_solution.cpp)
