#include <bits/stdc++.h>

#define int long long int
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long double ld;

using namespace std;

vector<int> res(212345);

void precalc()
{
    res[0] = 0;
    for (int i = 1; i < 212345; i++)
    {
        int aux = i, digI{0};
        while (aux > 0)
        {
            digI += aux % 10;
            aux /= 10;
        }
        res[i] = res[i - 1] + digI;
    }
}

void solve()
{
    int n;
    cin >> n;

    cout << res[n] << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    precalc();
    while (T--)
    {
        solve();
    }
}
