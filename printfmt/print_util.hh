#pragma once

#include <string>
#include <deque>

namespace dnl__ {
  std::string _format_arg(const char*);
  std::string _format_arg(const char);
  std::string _format_arg(void const*);
  std::string _format_arg(const int);
  std::string _format_arg(const double);

  std::deque <std::string> _parse_fmt(const std::string& fmt);
  size_t _strlen(const char* str);
};

namespace dnl__ {
  template <typename... Args>
  std::deque <std::string>
  _format_args(Args const&... args)
  {
    return std::deque <std::string> { _format_arg(args)... };
  }
}

