## File layout

- `include/grammar.h`: shared grammar types, constants, and printing helpers
- `include/grammar_io.h`: grammar and input reading
- `include/left_recursion.h`: left-recursion removal
- `include/first_follow.h`: FIRST and FOLLOW computation
- `include/parsing_table.h`: LL(1) parsing-table generation
- `include/parser.h`: predictive parsing and parse-tree building
- `src/main.cpp`: program entry point

## Input format

Write each production with spaces between symbols, for example:

```text
E -> E + T | T
T -> T * F | F
F -> ( E ) | id
```

Use `eps` for epsilon.

## Build

With `g++`:

```powershell
g++ src/*.cpp -I include -std=c++17 -Wall -Wextra -pedantic -o elite_parser.exe
```

Or with CMake:

```powershell
cmake -S . -B build
cmake --build build
```
