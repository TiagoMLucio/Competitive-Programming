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
    int n, q;
    readln(n, q);

    vi acc(n), ones(n);

    cin >> acc[0];

    ones[0] = acc[0] == 1 ? 1 : 0;

    for (int i = 1; i < n; i++)
    {
        int vi;
        cin >> vi;
        acc[i] = vi + acc[i - 1];
        ones[i] = (vi == 1) + ones[i - 1];
        dbg(ones[i]);
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        readln(l, r);
        l--;
        r--;

        if (l == r)
        {
            cout << "no" << endl;
            continue;
        }

        int sum = l > 0 ? acc[r] - acc[l - 1] : acc[r];
        int qnt_ones = l > 0 ? ones[r] - ones[l - 1] : ones[r];
        int len = r - l + 1;

        dbg(sum, qnt_ones, len);

        cout << (sum >= len + qnt_ones ? "yes" : "no") << endl;
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