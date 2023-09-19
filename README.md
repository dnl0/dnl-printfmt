# dnl::printfmt (dev)
Custom print function that nobody asked for.

## About
`dnl::printfmt` in branch `dev` is a version of `dnl::printfmt` that uses `puts` instead of inline assembly for output. This change dramatically increases performance, running even faster than `iostream` way of output. It also helps with
availability for multiple platforms. However, i will probably try to improve my inline assembly to make it just a little bit more exciting, instead of just relying on out-of-the-box instruments.

## Examples
### Available formats
```cpp
#include <iostream>
#include "dnl/print.hpp"

int main()
{
    dnl::printfmt("Good {}! It's {}:{} right now{}\n", 
                    "evening", 20, 45, '.');
}
```
### Using `format`
```cpp
#include "dnl/print.hpp"

int main()
{
	auto formatted_string = dnl::format("{}:{}:{}:{}:{}:{}:\n",
                            1.234, 42, 3.13, "str", (void*)1000, 'X'));
}
```
