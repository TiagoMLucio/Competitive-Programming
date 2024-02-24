#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using str = string;

#define sz(x) (int)((x).size())
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

using vi = vector<int>;
using vii = vector<ii>;
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

template <typename... Args>
void readln(Args &...args)
{
    ((cin >> args), ...);
}

template <typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
}

template <typename... Args>
void err(Args... args)
{
    ((cerr << args << " "), ...);
    cerr << endl;
}

void err_prefix(str func, int line, string args)
{
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
#else
#define dbg(...)
#endif

void solve()
{
    int n, k;
    readln(n, k);
    vi a(n), x(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    map<int, int> m;

    for (int i = 0; i < n; i++)
        m[abs(x[i])] += a[i];

    vii v(m.size());

    int count = 0;
    for (auto mi : m)
        v[count++] = mi;

    sort(all(v));

    bool yes = true;

    int ant = 0, bullets = 0;

    for (auto vi : v)
    {
        bullets += k * (vi.f - ant) - vi.s;
        ant = vi.f;
        if (bullets < 0)
        {
            yes = false;
            break;
        }
    }

    cout << (yes ? "yes" : "no") << endl;

    for (auto vi : v)
    {
        dbg(vi.f, vi.s);
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    int T;
    readln(T);
    while (T--)
    {
        solve();
    }
}