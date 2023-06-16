#include "print_util.hh"
#include <string>
#include <iostream>

size_t
dnl__::_strlen(const char* str)
{
  unsigned long size = 0;
  while (*str++ != '\0')
    ++size;
  return size;
}

std::deque <std::string>
dnl__::_parse_fmt(const std::string& fmt)
{
  std::deque <std::string> result {};

  auto begin = std::begin(fmt),
       end = std::end(fmt);

  std::string word {};
  bool inside_bracket = false; // useful for parsing indexes later
  for (; begin != end; ++begin) {
    if (*begin == '{') {
      inside_bracket = true;
    }
    else if (*begin == '}') {
      inside_bracket = false;
      result.emplace_back(word);
      word.clear();
    }
    else if (inside_bracket) {
      // @TODO
      continue;
    }
    else {
      word += *begin;
    }
  }
  result.emplace_back(word);

  return result;
}

std::string
dnl__::_format_arg(const char* arg)
{
  return arg;
}

std::string
dnl__::_format_arg(void* ptr)
{
  char result[15];
  snprintf(result, 15, "%p", ptr);
  return result;
}

std::string
dnl__::_format_arg(const char c)
{
  return std::string {c};
}
