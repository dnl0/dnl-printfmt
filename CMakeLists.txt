#
# @TODO: 
#     + make print_util.hpp things private: move them to
#        some subdirectory make that subdirectoy private
#

cmake_minimum_required(VERSION 3.14)

project("dnl::printfmt test")

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(printfmt)

#
# main test suite
#

add_executable(
  run_test
  test.cc
)

target_link_libraries(run_test dnl-printfmt)
target_compile_options(run_test PRIVATE -O3 -Wall -Wextra -Wpedantic)

add_custom_target(compare
  COMMAND @echo running dnl::printfmt...
  COMMAND @time -p ./run_test dnl-printfmt > /dev/null
  COMMAND @echo running std::iostream
  COMMAND @time -p ./run_test iostream > /dev/null
  DEPENDS run_test)

add_custom_target(test
  COMMAND @echo running dnl::printfmt 3 times...
  COMMAND @echo 1st run:
  COMMAND @time -p ./run_test dnl-printfmt > /dev/null
  COMMAND echo 2nd run:
  COMMAND @time -p ./run_test dnl-printfmt > /dev/null
  COMMAND @echo 3rd run:
  COMMAND @time -p ./run_test dnl-printfmt > /dev/null
  DEPENDS run_test)

#
# secondary test suite (to see if changes break something)
#

add_executable(
  run_simple_test
  simple_test.cc
)

target_link_libraries(run_simple_test dnl-printfmt)
target_compile_options(run_simple_test PRIVATE -Wall -Wextra -Wpedantic)

add_custom_target(simple_test
  COMMAND @echo running dnl::printfmt...
  COMMAND ./run_simple_test
  DEPENDS run_simple_test)

