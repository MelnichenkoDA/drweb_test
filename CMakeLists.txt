cmake_minimum_required(VERSION 3.12)
project(drweb_test VERSION 1.0 LANGUAGES CXX)

add_executable(main main.cpp)

add_subdirectory(src)
target_link_libraries(dictionary)