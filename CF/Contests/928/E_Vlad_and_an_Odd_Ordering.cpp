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
    int n, k;
    cin >> n >> k;

    int aux = k, p2 = 1;
    while (aux >= 0)
    {
        int qnt = (n + p2) / (2 * p2);
        if (aux <= qnt)
        {
            cout << p2 * (2 * aux - 1) << endl;
            break;
        }
        aux -= qnt;
        p2 *= 2;
    }
}

signed main()
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