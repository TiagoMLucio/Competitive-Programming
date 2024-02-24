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

    if (((n % 2 == 1 && k % 2 == 1) || (n % 2 == 0 && k % 2 == 0)) && n >= k)
    {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++)
        {
            cout << 1 << " ";
        }
        cout << n - k + 1 << endl;
    }
    else if (n % 2 == 0 && k % 2 == 1 && n >= 2 * k)
    {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++)
        {
            cout << 2 << " ";
        }
        cout << n - 2 * k + 2 << endl;
    }
    else
        cout << "NO" << endl;
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