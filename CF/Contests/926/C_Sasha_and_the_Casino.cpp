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
    ll k, x, a;
    cin >> k >> x >> a;

    ll lost{0};
    x++;
    while (x--)
    {
        ll y = lost / (k - 1) + 1;
        lost += y;
        if (lost < 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << (a >= lost ? "YES" : "NO") << endl;
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