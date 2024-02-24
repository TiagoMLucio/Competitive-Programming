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
    ll n, f, a, b;
    cin >> n >> f >> a >> b;

    ll pos{0}, m;

    for (ll i = 0; i < n; i++)
    {
        cin >> m;

        f -= min(a * (m - pos), b);

        pos = m;
    }

    cout << (f > 0 ? "YES" : "NO") << endl;
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