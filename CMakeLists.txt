cmake_minimum_required(VERSION 3.14)

project("dnl print")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_executable(
  main
  main.cpp
  include/dnl/print.cpp
  include/dnl/print_helper.cpp
)

target_include_directories(
  main
  PRIVATE
  include
)

target_compile_options(
  main
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -O3
)
