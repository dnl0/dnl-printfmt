#include "print_util.hh"
#include <string>

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

  std::string word {};
  word.reserve(fmt.size()+1);

  for (const auto& c: fmt) {
    switch (c) {
      case '{':
        break;
      case '}':
        result.emplace_back(word);
        word = "";
        break;
      default:
        word += c;
        break;
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
dnl__::_format_arg(const int arg)
{
  char result[15];
  snprintf(result, 15, "%d", arg);
  return result;
}

std::string
dnl__::_format_arg(const double arg)
{
  // @TODO: add precision
  char result[15];
  snprintf(result, 15, "%.4lf", arg);
  return result;
}

std::string
dnl__::_format_arg(const char arg)
{
  return std::string {arg};
}

std::string
dnl__::_format_arg(void const* arg)
{
  char result[15];
  snprintf(result, 15, "%p", arg);
  return result;
}
