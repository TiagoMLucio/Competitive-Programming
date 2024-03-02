#include <bits/stdc++.h>
#include <bitset>

#define int unsigned long long int
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

    map<int, int> m;

    int pairs{0};

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int aux = (~a) & (0x7fffffff);
        if (m[aux])
        {
            m[aux]--;
            pairs++;
        }
        else
            m[a]++;
    }

    cout << n - pairs << endl;
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