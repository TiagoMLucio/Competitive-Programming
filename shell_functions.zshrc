# CPP CP
CP_DIR=~/Documents/Competitive-Programming
declare -A platforms=( ["cf"]="codeforces" ["ac"]="atcoder" ["cc"]="codechef" )

co() {
        g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -DLOCAL -o "${1%.*}" $1;
}

run() {
        if [[ "$2" != "-n" && "$2" != "--noclear" ]]; then
                clear
        fi
        co "$1" && ./"${1%.*}" & fg;
}

codb() {
        g++ -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wsign-conversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_ASSERTIONS -ggdb3 -fsanitize=address,undefined -fanalyzer -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wuseless-cast -Wnull-dereference -Wdouble-promotion -Wmisleading-indentation -Wduplicated-branches -Walloca -Wzero-as-null-pointer-constant -Wpessimizing-move -Wredundant-move -Wextra-semi -Wshadow=local -Wundef -DLOCAL -ggdb3 -fmax-errors=2 -o "${1%.*}" $1;
}
       
debug() {
	codb $1 && gdb --tui -q ${1%.*} -ex "run <${1%.*}.in";
}

template() {
        cd "${CP_DIR}/" && code -gr "${CP_DIR}/templates/basic.cpp:171:5";
}

contest() {
        local platform=${platforms[${2:-cf}]}  
        local contest_dir="${CP_DIR}/${platform}/Contests/${1}"
        mkdir -p "${contest_dir}" && code -r "${contest_dir}/" && echo "${platforms}" && echo "${contest_dir}";
}

problems() {
        local platform=${platforms[${1:-cf}]} 
        local problems_dir="${CP_DIR}/${platform}/Problems"
        mkdir -p "${problems_dir}" && code -r "${problems_dir}/"
}