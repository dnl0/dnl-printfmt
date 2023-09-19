#include "printfmt/print.hh"

int main()
{
  dnl::println("Hello World");
  dnl::printfmt("{}:{}:{}:{}:{}:{}:\n",
      1.234, 42, 3.13, "str", (void*)1000, 'X');
}
