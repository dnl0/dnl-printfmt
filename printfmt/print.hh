/*
 * @TODO:
 *    + reserve sizes for constructors
 *    + use string_view instead of allocating strings for formatting
 *    + use this complicated way of calling functions for variadic templates
 */

#pragma once

#include "print_util.hh"

#include <iostream>
#include <numeric>
#include <string>
#include <deque>

namespace dnl {
  void println(const std::string&, FILE* os = stdout);

  template <typename... Args>
  std::string format(const std::string& fmt, Args const&... args)
  {
    std::deque <std::string> argumentsf = dnl__::_format_args(args...);
    std::deque <std::string> parsed_fmt = dnl__::_parse_fmt(fmt);
    
    if (argumentsf.size() != parsed_fmt.size()-1) {
      std::cerr << "\n\nfatal: string contains " << parsed_fmt.size() 
        << " placeholders, while argument list is of size " << argumentsf.size() << "\n";
      exit(EXIT_FAILURE);
    }

    // this method doesn't give significant performance boost yet but
    // i would like to test it on a larger strings to see if it does.
    size_t result_str_size = 
        std::accumulate(parsed_fmt.begin(), parsed_fmt.end(), 0,
          [](const int i, const std::string& s) -> size_t {
            return i + s.size();
          }) +
        std::accumulate(argumentsf.begin(), argumentsf.end(), 0,
          [](const int i, const std::string& s) -> size_t {
            return i + s.size();
          }) ;

    std::string result {};
    result.reserve(result_str_size);

    auto fmt_begin = std::begin(parsed_fmt);
    for (const auto& args: argumentsf) {
      result += *fmt_begin;
      result += args;
      ++fmt_begin;
    };

    if (fmt_begin != parsed_fmt.end())
      result += *fmt_begin;

    return result;
  }

  template <typename... Args>
  void printfmt(const std::string& fmt, Args const&... args)
  {
    puts(dnl::format(fmt, args...).c_str());
  }
};
