
# Competitive Programming

Welcome to my personal repository where I keep track of the competitive programming contests I participate in and my problem solutions. This repository will also serve as a storage for algorithms and templates I might use in the future.

## Repository Structure

- `AtCoder`: My solutions to AtCoder contests.
- `CodeChef`: My solutions to CodeChef contests.
- `CodeForces`: My solutions to Codeforces contests.
- `templates`: A personal collection of templates and algorithms for competitive programming.

## Custom Shell Functions for Compilation and Debugging

I use a set of custom shell functions to compile and debug my C++ solutions. These are added to my `~/.zshrc` file for convenience.

### Compile & Run

#### co

Compiles C++ files with standard optimization and common warning flags.

```bash
co() {
        g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -DLOCAL -o "${1%.*}" $1;
}
```

Usage:

```bash
co <filename>
```

#### run

Compiles with co() and runs.

```bash
run() {
       co $1 && ./${1%.*} & fg;
}
```

Usage:

```bash
run <filename>
```

#### codb

Compiles C++ files with extensive warnings, static analysis, and debugging symbols.

```bash
codb() {
        g++ -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_ASSERTIONS -ggdb3 -fsanitize=address,undefined -fanalyzer -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wuseless-cast -Wnull-dereference -Wdouble-promotion -Wmisleading-indentation -Wduplicated-branches -Walloca -Wzero-as-null-pointer-constant -Wpessimizing-move -Wredundant-move -Wextra-semi -Wshadow=local -Wundef -DLOCAL -ggdb3 -fmax-errors=2 -o "${1%.*}" $1;
}
```

Usage:

```bash
codb <filename>
```

### Debugging with GDB

#### debug

Compiles with codb() and launches gdb in TUI mode with the specified executable and input file.

```bash
debug() {
	codb $1 && gdb --tui -q ${1%.*} -ex "run <${1%.*}.in";
}
```

Usage:

```bash
debug <filename>
```

### How to Set Up

1. Copy the function definitions into your `~/.zshrc` file.
2. Run `source ~/.zshrc` or restart your terminal to apply the changes.

## License

The content in this repository is not open for contribution and is for personal use only. It is not licensed for public use.
