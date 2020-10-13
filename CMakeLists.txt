cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})
add_link_options(-fsanitize=address)
add_compile_options(-fsanitize=address -g)
add_executable(test_1 test_1/task_1.c)
