cmake_minimum_required(VERSION 3.14)

project("dnl_printfmt")

set(CMAKE_CXX_STANDARD 11)

# let's hope O3 will save my terrible code
set(CXX_COMPILE_FLAGS -O3 -Wall -Wextra -Wpedantic)

set(DNL_PRINTFMT_HEADERS print.hh print_util.hh)
set(DNL_PRINTFMT_SOURCES print.cc print_util.cc)

add_library(dnl_printfmt 
  ${DNL_PRINTFMT_SOURCES} ${DNL_PRINTFMT_HEADERS})

target_compile_options(dnl_printfmt PRIVATE 
  ${CXX_COMPILE_FLAGS})

set_target_properties(dnl_printfmt PROPERTIES 
  PUBLIC_HEADER "${DNL_PRINTFMT_HEADERS}")
