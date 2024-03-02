#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    ll max{n}, min{1}, sum{0};

    for (ll i = 0; i < n; i += y)
    {
        if (i % x != 0 && i % y == 0)
            sum -= min++;
    }
    for (ll i = 0; i < n; i += x)
    {
        if (i % x == 0 && i % y != 0)
            sum += max--;
    }

    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}