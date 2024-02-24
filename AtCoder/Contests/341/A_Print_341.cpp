#include <bits/stdc++.h>

#define int long long int
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long double ld;

using namespace std;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n + 1; i++)
        cout << (i % 2 == 0 ? 1 : 0);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}