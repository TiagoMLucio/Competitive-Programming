
# Competitive Programming

Welcome to my personal repository where I keep track of the competitive programming contests I participate in and my problem solutions. This repository will also serve as a storage for algorithms and templates I might use in the future.

## Repository Structure

- `AtCoder`: My solutions to AtCoder contests.
- `CF`: My solutions to Codeforces contests.
- `CodeChef`: My solutions to CodeChef contests.
- `templates`: A personal collection of templates and algorithms for competitive programming.

## Custom Shell Functions for Compilation and Debugging

I use a set of custom shell functions to compile and debug my C++ solutions. These are added to my `~/.bashrc` file for convenience.

### Compilation Commands

#### compile

Compiles C++ files with standard optimization and common warning flags.

```bash
function compile {
	g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -DLOCAL -o $1{,.cpp}		
}
```

Usage:

```bash
compile <filename_without_extension>
```

#### compilew

Compiles C++ files with extensive warnings, static analysis, and debugging symbols.

```bash
function compilew {
        g++ -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wsign-conversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_ASSERTIONS -ggdb3 -fsanitize=address,undefined -fanalyzer -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wuseless-cast -Wnull-dereference -Wdouble-promotion -Wmisleading-indentation -Wduplicated-branches -Walloca -Wzero-as-null-pointer-constant -Wpessimizing-move -Wredundant-move -Wextra-semi -Wshadow=local -Wundef -DLOCAL -ggdb3 -fmax-errors=2 -o $1{,.cpp}
}
```

Usage:

```bash
compilew <filename_without_extension>
```

### Debugging with GDB

#### debug

Launches gdb in TUI mode with the specified executable and input file.

```bash
function debug {
    	gdb --tui -q $1 -ex "run <$1.in"
}
```

Usage:

```bash
debug <executable_name>
```

### How to Set Up

1. Copy the function definitions into your `~/.bashrc` file.
2. Run `source ~/.bashrc` or restart your terminal to apply the changes.

## License

The content in this repository is not open for contribution and is for personal use only. It is not licensed for public use.
