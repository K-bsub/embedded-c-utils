cmake_minimum_required(VERSION 3.16)
project(embedded_c_utils C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Werror -pedantic)

add_library(embedded_c_utils
    src/ring_buffer.c
)
target_include_directories(embedded_c_utils PUBLIC include)

add_executable(test_ring_buffer
    tests/test_ring_buffer.c
)
target_link_libraries(test_ring_buffer PRIVATE embedded_c_utils)

enable_testing()
add_test(NAME ring_buffer_tests COMMAND test_ring_buffer)
