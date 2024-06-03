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
 
SFINAE(IsDefaultI, decltype(std::cin >> std::declval<T &>()));
SFINAE(IsDefaultO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(IsIterable, decltype(std::begin(std::declval<T>())));
SFINAE(IsQueue, decltype(std::declval<T>().push(std::declval<typename T::value_type>()), std::declval<T>().pop(), std::declval<T>().front()));
SFINAE(IsStack, decltype(std::declval<T>().push(std::declval<typename T::value_type>()), std::declval<T>().pop(), std::declval<T>().top()));

template <auto &is> struct Reader {
    template <class T> void Impl(T &t) {
        if constexpr (IsDefaultI<T>::value) is >> t;
        else if constexpr (IsIterable<T>::value) {
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
        return print_nd && (IsIterable<T>::value or IsTuple<T>::value) ? '\n' : ' ';
    }
    template <class T> void Impl(T const &t) const {
        if constexpr (IsDefaultO<T>::value) os << t;
        else if constexpr (IsIterable<T>::value) {
            if (debug) os << '{';
            int i = 0;
            for (auto &&x : t)
                ((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));
            if (debug) os << '}';
        } else if constexpr (IsQueue<T>::value || IsStack<T>::value) {
            T tmp = t;
            if (debug) os << '{';
            while (!tmp.empty()) {
                Impl(tmp.front());
                tmp.pop();
                if (!tmp.empty()) os << comma() << Space(tmp.front());
            }
            if (debug) os << '}';
        }else if constexpr (IsTuple<T>::value) {
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

void solve()
{
    def(str, s1, s2);
    def(int, t, q);

    int n = sz(s1);
    
    set<int> diff;
    queue<ii> blocked;

    for(int i = 0; i < n; i++)
        if(s1.at(i) != s2.at(i))
            diff.insert(i);

    for(int i = 0; i < q; i++) {
        def(int, type);

        if(!blocked.empty() && i >= blocked.front().f + t) {
            diff.insert(blocked.front().s);
            blocked.pop();
        }

        switch (type) {
            case 1: {
                def(int, pos); pos--;
                auto it = diff.find(pos);
                if(it != diff.end()) {
                    diff.erase(it); 
                    blocked.push({i, pos});
                }
                break;
            }
            case 2: {
                def(int, strIdx1, pos1, strIdx2, pos2); pos1--; pos2--;
                str *str1 = strIdx1 == 1 ? &s1 : &s2;
                str *str2 = strIdx2 == 1 ? &s1 : &s2;

                swap(str1->at(pos1), str2->at(pos2));

                auto it1 = diff.find(pos1);
                auto it2 = diff.find(pos2);

                if (s1.at(pos1) != s2.at(pos1)) diff.insert(pos1);
                else if (it1 != diff.end()) diff.erase(it1);
                if (s1.at(pos2) != s2.at(pos2)) diff.insert(pos2);
                else if (it2 != diff.end()) diff.erase(it2);
                break;
            }
            case 3: {
                ps(diff.empty() ? "YES" : "NO");
                break;
            }
        }     

        dbg(s1, s2, diff, blocked);
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