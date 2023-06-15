# dnl::print
Custom print function that nobody asked for.

## About
`dnl::print` was made with two goals in mind: performance and ease of use. However, I failed miserably at both of those, and i have data to back it up.

Using benchmarks from [fmt benchmarks](https://github.com/fmtlib/format-benchmark), it was calculated, that `dnl::printfmt` does the worst out of them all: being, on average, about 20% slower than `iostream`. That being said, there are few points that need to be considered before using `dnl::print`.

### Pros
- cool namespace
- still easier to use than `iostream`
### Cons
- slow
- unavailable on Windows and BSD
- limited functionality
- not tested properly
- no support
- probably contains a lot of bugs
- uses inline assembly
- generally weird design decisions

## Examples
### Available formats
```cpp
#include <iostream>
#include "dnl/print.hpp"

int main()
{
    dnl::printfmt(std::cout, "Good {}! It's {}:{} right now{}\n", 
                             "evening", 20, 45, '.');
}
```
### Printing and formatting separately
```cpp
#include "dnl/print.hpp"

int main()
{
	// if not specified, `print` will use std::cout by default
	dnl::print(dnl::format("{}:{}:{}:{}:{}:{}:\n",
                           1.234, 42, 3.13, "str", (void*)1000, 'X'));
}
```
