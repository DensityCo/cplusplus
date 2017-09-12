cmake_minimum_required (VERSION 3.1.0)
project(scope)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-O0 -ggdb -g3")
set(CMAKE_C_FLAGS_DEBUG_INIT "-O0 -ggdb -g3")

add_executable(global_example global_example.cc)
add_executable(static_global_example static_global_example.cc)
add_executable(static_function_variable_example static_function_variable_example.cc)

#
# NOTE (BNB): This target is supposed to error out. Trying to prove a point.
#
# add_executable(scope_example scope_example.cc)

add_executable(block_scope_example block_scope_example.cc)

add_executable(c_heap_example c_heap_example.c)
add_executable(cc_heap_example cc_heap_example.cc)

add_executable(pointer_example pointer_example.cc)
add_executable(bad_pointer_example bad_pointer_example.cc)
