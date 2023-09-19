#include "print.hh"

// @TODO: add support for indexed formatting, 
//        e.g.: "this is {1}, but this is {0}, and with no {1} there's no {0}", "gain", "pain"

void
dnl::println(const std::string& str, FILE* os)
{
  puts((str+"\n").c_str());
}
