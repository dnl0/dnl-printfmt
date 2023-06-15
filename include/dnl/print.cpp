#include "print.hpp"

// @TODO: add support for indexed formatting, 
//        e.g.: "this is {1}, but this is {0}, and with no {1} there's no {0}", "gain", "pain"

void
dnl::write(const char* str, FILE* os)
{
  // @TODO: write to different streams
  const size_t size = dnl__::_strlen(str);

  __asm__ volatile (
#ifdef __APPLE__
    "mov   $0x2000004,  %%rax \n"
#elif __linux__
    "movq $1,   %%rax \n"
#endif
    "movq $1,   %%rdi \n"
    "movq %0,   %%rsi \n"
    "mov  %1,   %%rdx \n"
    "syscall \n"
    :
    : "r" (str), "r" (size)
    : "%rax"
  );
}

void
dnl::write(const char c, FILE* os)
{
  char str_from_char[2];
  snprintf(str_from_char, 2, "%c", c);
  dnl::write(str_from_char, os);
}

void
dnl::print(const std::string& str, std::ostream& os)
{
  // @
  if (&os == &std::cout)
    dnl::write(str.c_str(), stdout);
  else if (&os == &std::cerr)
    dnl::write(str.c_str(), stderr);
  else
    /*not supported yet*/;
}

void
dnl::println(const std::string& str, std::ostream& os)
{
  if (&os == &std::cout)
    dnl::write((str+"\n").c_str(), stdout);
  else if (&os == &std::cerr)
    dnl::write((str+"\n").c_str(), stderr);
  else
    /*not supported yet*/;
}
