# dnl::printfmt
Custom print function that nobody asked for.

## About
`dnl::printfmt` was made with two goals in mind: performance and ease of use. However, I failed miserably at both of those, and i have data to back it up.

Using benchmarks from [fmt benchmarks](https://github.com/fmtlib/format-benchmark), it was calculated, that `dnl::printfmt` does the worst out of them all (except for `boost::format`): being, on average, about 20% slower than `iostream` (though only with `-O3` option, without any optimisation it's much slower). That being said, there are few points that need to be considered before using `dnl::printfmt`.

### Pros
- cool namespace
- still easier to use than `iostream` (not a high bar)
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
    dnl::printfmt(stdout, "Good {}! It's {}:{} right now{}\n", 
                            "evening", 20, 45, '.');
}
```
### Printing and formatting separately
```cpp
#include "dnl/print.hpp"

int main()
{
	// if not specified, `print` will use stdout by default
	dnl::print(dnl::format("{}:{}:{}:{}:{}:{}:\n",
                           1.234, 42, 3.13, "str", (void*)1000, 'X'));
}
```

## Test
Check out my fork of [fmt format-benchmark](https://github.com/dnl0/format-benchmark) with `dnl::printfmt` included if you want to test it yourself.

## See also
You can also check out `dev` branch, for a faster, "improved" version.
