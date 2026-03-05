cmake_minimum_required(VERSION 3.10)

project(swap)

# create static library
add_library(swap_static STATIC src/swap.cpp)

# set the static library name:"libsawp.a"
set_target_properties(swap_static PROPERTIES OUTPUT_NAME "swap")

target_include_directories(swap_static PUBLIC include)

add_executable(test_swap src/main.cpp)

target_link_libraries(test_swap swap_static)

