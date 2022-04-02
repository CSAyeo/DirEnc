cmake_minimum_required(VERSION 3.21)
project(Practical)

set(CMAKE_CXX_STANDARD 14)
add_library(openssl SHARED IMPORTED)
set_target_properties(openssl PROPERTIES IMPORTED_LOCATION "")
add_executable(Practical main.cpp)
