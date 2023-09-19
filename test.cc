#include "printfmt/print.hh"

#include <iostream>
#include <iomanip>

int main(int argc, char* argv[])
{
  if (argc == 1) {
    std::cerr << "fatal: print function is not specified\n";
    exit(EXIT_FAILURE);
  }

  const std::string which = argv[1];
  const long maxIter = 2000000L;

  if (which == "dnl-printfmt") {
    for (long i = 0; i < maxIter; ++i)
      dnl::printfmt("{}:{}:{}:{}:{}:{}:\n",
          1.234, 42, 3.13, "str", (void*)1000, 'X');
  }
  else if (which == "iostream") {
    for (long i = 0; i < maxIter; ++i)
      std::cout << std::setprecision(10) << std::fixed << 1.234 << ':'
          << std::resetiosflags(std::ios::floatfield)
          << std::setw(4) << std::setfill('0') << 42 << std::setfill(' ') << ':'
          << std::setiosflags(std::ios::showpos) << 3.13 << std::resetiosflags(std::ios::showpos) << ':'
          << "str" << ':'
          << (void*)1000 << ':'
          << 'X' << ":%\n";
  }
}
