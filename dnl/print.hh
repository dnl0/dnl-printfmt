#pragma once

#include "print_util.hh"

#include <iostream>
#include <string>
#include <deque>

namespace dnl {
  void write(const char*, FILE* os = stdout);
  void write(const char,  FILE* os = stdout);

  void print(const std::string&, std::ostream& os = std::cout);
  void println(const std::string&, std::ostream& os = std::cout);

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

    std::string result {};
    auto fmt_begin = parsed_fmt.begin();
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
  void printfmt(std::ostream& os, const std::string& fmt, Args const&... args)
  {
    dnl::print(dnl::format(fmt, args...), os);
  }
};
