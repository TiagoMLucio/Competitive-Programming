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
    int n, m;
    cin >> n >> m;

    int sum{0};

    while (n < m)
    {
        sum += 1 + m % 2;
        m = (m + 1) / 2;
    }

    sum += n - m;

    cout << sum << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}