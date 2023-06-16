cmake_minimum_required(VERSION 3.14)

project("dnl::printfmt testing")

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(dnl)

add_executable(test-dnl-printfmt test/test.cc)

target_link_libraries(test-dnl-printfmt dnl_printfmt)
