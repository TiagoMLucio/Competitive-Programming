#include "bits/stdc++.h"
#include <chrono>
using namespace std;

using ll = long long;
using ld = long double;
using str = string;

#define sz(x) static_cast<int>((x).size())
#define MAXX 1073741823
#define MAX (1 << 20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define endl '\n'
#define int ll

using ii = pair<int, int>;
#define mp make_pair
#define f first
#define s second

using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;

using vi = vector<int>;
using vii = vector<ii>;
using viii = vector<iii>;
using viiii = vector<iiii>;
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

inline namespace IO {
#define SFINAE(x, ...)                                                         \
    template <class, class = void> struct x : std::false_type {};              \
    template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
 
SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));
SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

template<typename T, typename = std::enable_if_t<Iterable<T>::value && !DefaultI<T>::value>>
std::istream& operator>>(std::istream& is, T& container) {
    for(auto& item : container)
        is >> item; 
    return is;
}

template<typename T1, typename T2>
std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p) {
    return is >> p.first >> p.second;
}

template<typename... Ts>
std::istream& operator>>(std::istream& is, std::tuple<Ts...>& tup) {
    std::apply([&is](auto&... args) { ((is >> args), ...); }, tup);
    return is;
}

template <auto &is> struct Reader {
    template <class T> void Impl(T &t) {
        if constexpr (DefaultI<T>::value || Iterable<T>::value || IsTuple<T>::value) is >> t;
        else static_assert(sizeof(T) == 0, "No matching type for read");
    }
    template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); }
};
 
template <class... Ts> void re(Ts &...ts) { Reader<cin>{}.read(ts...); }
#define def(t, ...)                                                        \
    t __VA_ARGS__;                                                                    \
    re(__VA_ARGS__);
 
template<typename T, typename = std::enable_if_t<Iterable<T>::value && !DefaultO<T>::value>>
std::ostream& operator<<(std::ostream& os, const T& container) {
    int i = 0;
    for (const auto &item : container)
        os << (i++ ? " " : "") << item;
    return os;
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    return os << p.first << " " << p.second;
}

template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& tup) {
    std::apply([&os](const auto&... args) {
        size_t n = 0;
        ((os << (n++ ? " " : "") << args), ...);
    }, tup);
    return os;
}

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
#define dbgn(args...)
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

void solve()
{
    def(int,n);
    
    int x {0}, y {0}, z {0};

    while(n--) {
        def(int, xi, yi, zi);
        x+= xi; y += yi; z+= zi;
    }

    ps (x == 0 && y == 0 && z == 0 ? "YES" : "NO");
}

signed main()
{
    setIO();	

    int T{1};
    while (T--) solve();

    // dbg(time_elapsed());
}