
# Competitive Programming

Welcome to my personal repository where I keep track of the competitive programming contests I participate in and my problem solutions. This repository will also serve as a storage for algorithms and templates I might use in the future.

## Repository Structure

- `atcoder`: My solutions to AtCoder contests.
- `codechef`: My solutions to CodeChef contests.
- `codeforces`: My solutions to Codeforces contests.
- `cses`: My solutions to Cses problems.
- `maratona`: My solutions to problems and phases from Maratona.
- `templates`: A personal collection of templates and algorithms for competitive programming.

## Custom Shell Functions for Compilation and Debugging

I use a set of custom shell functions to compile and debug my C++ solutions. These are added to my `~/.zshrc` file for convenience.

### How to Set Up

1. Copy the function definitions into your `~/.zshrc` file.
2. Run `source ~/.zshrc` or restart your terminal to apply the changes.

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

### Navigation

Firstly, setup the following variables:

- `CP_DIR`: Directory to the Competitive-Programming folder. 
- `platforms`: Map to the platforms configured in the folder.

```bash
CP_DIR="~/Documents/Competitive-Programming"
declare -A platforms=( ["cf"]="codeforces" ["ac"]="atcoder" ["cc"]="codechef" ["cs"]="cses" )
```

#### Template File

Opens the tamplate file in VS Code.

```bash
template() {
        cd "${CP_DIR}/" && code -gr "${CP_DIR}/templates/basic.cpp:171:5";
}
```

Usage:

```bash
template
```


#### New Contest

Sets up a new directory for a contest from a specified platform (default is Codeforces) and opens it in VS Code.

```bash
contest() {
        local platform=${platforms[${2:-cf}]}  
        local contest_dir="${CP_DIR}/${platform}/Contests/${1}"
        mkdir -p "${contest_dir}" && code -r "${contest_dir}/" && echo "${platform}" && echo "${contest_dir}";
}
```

Usage:

```bash
contest <contest_id> [ cf | ac | cc ]
```

#### Problems Folder

Opens the problems directory for a specified platform (default is Codeforces) in VS Code.

```bash
problems() {
        local platform=${platforms[${1:-cf}]} 
        local problems_dir="${CP_DIR}/${platform}/Problems"
        mkdir -p "${problems_dir}" && code -r "${problems_dir}/"
}
```

Usage:

```bash
problems [ cf | ac | cc ]
```

## License

The content in this repository is not open for contribution and is for personal use only. It is not licensed for public use.
