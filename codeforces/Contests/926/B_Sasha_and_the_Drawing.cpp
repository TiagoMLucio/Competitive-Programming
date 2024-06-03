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
    ll n, k;
    cin >> n >> k;

    if (k <= 4 * (n - 1))
    {
        cout << k / 2 + k % 2 << endl;
        return;
    }

    cout << k - 2 * (n - 1) << endl;
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