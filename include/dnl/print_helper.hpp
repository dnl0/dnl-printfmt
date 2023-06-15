#pragma once

#include <string>
#include <deque>

namespace dnl__ {
  std::string _format_arg(const char*);
  std::string _format_arg(const char);
  std::string _format_arg(void*);
  std::deque <std::string> _parse_fmt(const std::string& fmt);
  size_t _strlen(const char* str);
};

namespace dnl__ {
  template <typename T>
  std::string
  _format_arg(const T& arg)
  {
    return std::to_string(arg);
  }

  template <typename T>
  void
  _format_args_to_deque(std::deque <std::string>& result, const T& arg)
  {
    result.emplace_back(_format_arg(arg));
  }

  template <typename T, typename... Args>
  void
  _format_args_to_deque(std::deque <std::string>& result, 
      const T& arg, Args const&... args)
  {
    result.emplace_back(_format_arg(arg));
    _format_args_to_deque(result, args...);
  }

  template <typename T, typename... Args>
  std::deque <std::string>
  _format_args(const T& arg, Args... args)
  {
    std::deque <std::string> result {};

    _format_args_to_deque(result, arg, args...);

    return result;
  }
}

