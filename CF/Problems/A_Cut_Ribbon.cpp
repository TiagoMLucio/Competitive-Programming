#include <bits/stdc++.h>

#define int long long int
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long double ld;

using namespace std;

vector<int> m(4123, -1);

int dp(int x, int a, int b, int c)
{
    if (x <= 0)
        return 0;

    if (m[x] >= 0)
        return m[x];

    int aux = 1 + max(max(dp(x - a, a, b, c), dp(x - b, a, b, c)), dp(x - c, a, b, c));

    if (aux > 1)
        return m[x] = aux;

    if (x == a || x == b || x == c)
        return m[x] = 1;

    return m[x] = 0;
}

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << dp(n, a, b, c) << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}