#include <bits/stdc++.h>
#include <limits>

#define int long long int
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long double ld;

using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int mmc = lcm(n, m);

    int qnt = mmc / n - 1 + mmc / m - 1;

    int rest;

    int p{1}, q{1};
    for (int i = 0; i < qnt; i++)
    {
        int aux1 = n * p;
        int aux2 = m * q;
        if (aux1 < aux2)
            p++;
        else
            q++;
        if (i == (k - 1) % qnt)
        {
            rest = min(aux1, aux2);
            break;
        }
    }

    cout << rest + (k - 1) / qnt * mmc << endl;
}



signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}