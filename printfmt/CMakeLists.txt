cmake_minimum_required(VERSION 3.14)

project("dnl-printfmt")

set(CMAKE_CXX_STANDARD 11)

set(CXX_COMPILE_FLAGS -O3)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(DNL_PRINTFMT_HEADERS print.hh print_util.hh)
set(DNL_PRINTFMT_SOURCES print.cc print_util.cc)

add_library(dnl-printfmt 
  ${DNL_PRINTFMT_SOURCES} ${DNL_PRINTFMT_HEADERS})

target_compile_options(dnl-printfmt PRIVATE 
  ${CXX_COMPILE_FLAGS})

set_target_properties(dnl-printfmt PROPERTIES 
  PUBLIC_HEADER "${DNL_PRINTFMT_HEADERS}")
