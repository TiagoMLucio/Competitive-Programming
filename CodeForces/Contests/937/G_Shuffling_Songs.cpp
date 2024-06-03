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

void solve1()
{
    def(int, n);
    V<pair<str, str>> v(n);
    re(v);
    
    int ans = n;

    do {
        int maxseq = 1, cur = 1;
        for(int i = 1; i < n; i++) {
            if (v[i].f == v[i - 1].f || v[i].s == v[i - 1].s) {
                cur++;
                maxseq = max(maxseq, cur);
            } else cur = 1;
        }
        ans = min(ans, n - maxseq);
    } while(next_permutation(all(v)));

    ps(ans);
}

V<pair<str, str>> v;
V<tuple<int, int, bool>> v2;
vi memo;

int dp(tuple<int, int, bool> x) {
    vi possible;
    for(int i = 0; i < sz(v2); i++)
        if (!get<2>(v2.at(i)) && (get<0>(v2.at(i)) == get<0>(x) || get<1>(v2.at(i)) == get<1>(x)))
            possible.pb(i);


    int aux = 0;

    for (int i = 0; i < sz(v2); i++) 
        aux += get<2>(v2.at(i)) ? (1 << i) : 0;

        aux <<= 4;

    for (int i = 0; i < sz(v2); i++)
        if (get<0>(v2.at(i)) == get<0>(x) && get<1>(v2.at(i)) == get<1>(x)) {
            aux += i;
            break;
        }

    dbg(x, possible, v2, memo.at(aux));

    if(sz(possible) == 0) {memo.at(aux) = 0; return 0;}

    if (memo.at(aux) != -1) return memo.at(aux);

    int maxd = 0;

    for(int p: possible) {
        get<2>(v2.at(p)) = true;
        maxd = max(maxd, dp(v2.at(p)) + 1);
        get<2>(v2.at(p)) = false;
    }         

    dbg(x, maxd);

    memo.at(aux) = maxd;

    return maxd;
}

void solve()
{
    def(int, n);
    v.resize(n);
    memo.resize(1 << (n + 4), -1);
    re(v);

    map<str, int> freqg, freqw;

    for(auto x: v) {
        freqg[x.f]++;
        freqw[x.s]++;
    }

    V<pair<str, int>> gs, ws;

    for(auto gi: freqg) gs.pb(gi);
    for(auto wi: freqw) ws.pb(wi);

    for(auto x: v) {
        int gcompress = 0;
        int wcompress = 0;
        for(int i = 0; i < sz(gs); i++) {
            if (x.f == gs.at(i).f) gcompress = i; 
        }
        for(int i = 0; i < sz(ws); i++) {
            if (x.s == ws.at(i).f) wcompress = i; 
        }
        v2.pb({gcompress, wcompress, false});

    }
    
    int maxd = 0;

    dbg(v2);

    for(int i = 0; i < n; i++) {
        get<2>(v2.at(i)) = true;
        maxd = max(maxd, dp(v2.at(i)) + 1);
        dbg(v2.at(i), maxd);
        get<2>(v2.at(i)) = false;
    }

    dbg(maxd);

    ps(n - maxd);
    v.erase(all(v));
    v2.erase(all(v2));
    memo.erase(all(memo));
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