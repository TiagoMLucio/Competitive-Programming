#include "bits/stdc++.h"
#include <chrono>
using namespace std;

using ll = long long;
using ld = long double;
using str = string;

#define sz(x) static_cast<int>((x).size())
#define endl '\n'
#define int ll

using ii = pair<int, int>;
#define mp make_pair
#define f first
#define s second

using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
#define mt make_tuple

template<class T> using V = vector<T>;
using vi = V<int>;
using vii = V<ii>;
using viii = V<iii>;
using viiii = V<iiii>;
using vb = V<bool>;
using vs = V<str>;
using vd = V<double>;
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define allr(x) (x).rbegin(), (x).rend()

const int MODN = static_cast<int>(1e9+7);
const int INF = 0x3f3f3f3f;
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!

inline namespace IO {
#define SFINAE(x, ...)                                                         \
    template <class, class = void> struct x : std::false_type {};              \
    template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
 
SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));
SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

template <auto &is> struct Reader {
    template <class T> void Impl(T &t) {
        if constexpr (DefaultI<T>::value) is >> t;
        else if constexpr (Iterable<T>::value) {
            for (auto &x : t) Impl(x);
        } else if constexpr (IsTuple<T>::value) {
            std::apply([this](auto &...args) { (Impl(args), ...); }, t);
        } else static_assert(IsTuple<T>::value, "No matching type for read");
    }
    template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); }
};
 
template <class... Ts> void re(Ts &...ts) { Reader<cin>{}.read(ts...); }
#define def(t, ...)                                                        \
    t __VA_ARGS__;                                                                    \
    re(__VA_ARGS__);

template <auto &os, bool debug, bool print_nd> struct Writer {
    string comma() const { return debug ? "," : ""; }
    template <class T> constexpr char Space(const T &) const {
        return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n' : ' ';
    }
    template <class T> void Impl(T const &t) const {
        if constexpr (DefaultO<T>::value) os << t;
        else if constexpr (Iterable<T>::value) {
            if (debug) os << '{';
            int i = 0;
            for (auto &&x : t)
                ((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));
            if (debug) os << '}';
        } else if constexpr (IsTuple<T>::value) {
            if (debug) os << '(';
            std::apply(
                [this](auto const &...args) {
                    int i = 0;
                    (((i++) ? (os << comma() << " ", Impl(args)) : Impl(args)), ...);
                }, t);
            if (debug) os << ')';
        } else static_assert(IsTuple<T>::value, "No matching type for print");
    }
    template <class T> void ImplWrapper(T const &t) const {
        if (debug) os << "\033[0;31m";
        Impl(t);
        if (debug) os << "\033[0m";
    }
    template <class... Ts> void print(Ts const &...ts) const {
        ((Impl(ts)), ...);
    }
    template <class F, class... Ts>
    void print_with_sep(const std::string &sep, F const &f,
                        Ts const &...ts) const {
        ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\n';
    }
    void print_with_sep(const std::string &) const { os << '\n'; }
};
 
template <class... Ts> void pr(Ts const &...ts) {
    Writer<cout, false, true>{}.print(ts...);
}
template <class... Ts> void ps(Ts const &...ts) {
    Writer<cout, false, true>{}.print_with_sep(" ", ts...);
}
}  // namespace IO
 
inline namespace Debug {
template <typename... Args> void err(Args... args) {
    Writer<cerr, true, false>{}.print_with_sep(" | ", args...);
}
template <typename... Args> void errn(Args... args) {
    Writer<cerr, true, true>{}.print_with_sep(" | ", args...);
}
 
void err_prefix(str func, int line, string args) {
    cerr << "\033[0;31m\u001b[1mDEBUG\033[0m"
         << " | "
         << "\u001b[34m" << func << "\033[0m"
         << ":"
         << "\u001b[34m" << line << "\033[0m"
         << " - "
         << "[" << args << "] = ";
}
 
#ifdef LOCAL
#define dbg(...) err_prefix(__FUNCTION__, __LINE__, #__VA_ARGS__), err(__VA_ARGS__)
#define dbgn(...) err_prefix(__FUNCTION__, __LINE__, #__VA_ARGS__), errn(__VA_ARGS__)
#else
#define dbg(...)
#define dbgn(...)
#endif
 
const auto beg_time = std::chrono::high_resolution_clock::now();
// https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1
double time_elapsed() {
    return chrono::duration<double>(std::chrono::high_resolution_clock::now() -
                                    beg_time)
        .count();
}
}  // namespace Debug

inline namespace FileIO {
void setIn(str s) {
    if (!freopen(s.c_str(), "r", stdin))
        fprintf(stderr, "Failed to open input file: %s\n", s.c_str());
}
void setOut(str s) {
    if (!freopen(s.c_str(), "w", stdout))
        fprintf(stderr, "Failed to open output file: %s\n", s.c_str());
}
void setIO(str s = "") {
    cin.tie(nullptr)->sync_with_stdio(false);  // unsync C / C++ I/O streams
    cout << fixed << setprecision(12);
    // cin.exceptions(cin.failbit);
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");
}
}  // namespace FileIO

int pow(int a, int b) {
    int res {1};
    while(b > 0) {
        res *= a;
        b--;
    }
    return res;
}

void solve() {
    def(str, s);
    
    int sys = 0;

    if (s.at(0) == 'R') {
        int i = 0;
        for(int ii = 1; ii < sz(s); ii++) {
            if (i && s.at(ii) == 'C') {
                sys = 1;
                break;
            } else if (s.at(ii) >= '0' && s.at(ii) <= '9') i = ii;
        }
    }

    if(sys) {
        str num1, num2;
        bool afterC = false;
        for(int i = 1; i < sz(s); i++) {
            if (afterC) num2 += s.at(i);
            else {
                if (s.at(i) == 'C') afterC = true;
                else num1 += s.at(i);
            }
        }

        int n1 {stoi(num1)}, n2 {stoi(num2) - 1};

        int c = log(25 * n2 / 26 + 1) / log(26);

        dbg(n2, c);

        n2 -= 26 * (pow(26, c) - 1) / 25; 

        dbg(26 * (pow(26, c) - 1) / 25, n2);

        str col;

        for(int i = 0; i <= c; i++)
            col.pb('A');

        int i {0};

        while(n2 > 0) {
            col.at(i) += (n2 % 26);
            n2 /= 26;
            i++;
        }

        reverse(all(col));

        cout << col << n1 << endl;
    } else {
        str col, row;

        for(auto c: s) {
            if (c >= '0' && c <= '9') row.pb(c);
            else col.pb(c);
        }

        int nc {26 * (pow(26, sz(col) - 1) - 1) / 25 + 1};

        int pow26 = 1;

        for(int i = sz(col) - 1; i >= 0; i--) {
            nc += (col.at(i) - 'A') * pow26;
            pow26 *= 26;
        }

        cout << 'R' << row << 'C' << nc << endl;
    }
}

signed main()
{
    setIO();	

    def(int, T);
    while (T--) {
        solve();
    }

    // dbg(time_elapsed());
}