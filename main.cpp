#include <dnl/print.hpp>

int main()
{
  dnl::write("hello world");
  dnl::write('\n');

  dnl::print("Hello world\n");
  dnl::println("Hello, world");

  dnl::println(dnl::format("Good {}! It's {}:{} right now{}", "morning", 9, 30, ';'));
  dnl::printfmt(std::cout, "Good {}! It's {}:{} right now{}\n", "evening", 20, 45, '.');

  dnl::printfmt(std::cout, "{}:{}:{}:{}:{}:{}:\n",
      1.234, 42, 3.13, "str", (void*)1000, 'X');
}
