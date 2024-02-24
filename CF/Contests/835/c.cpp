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
    int l, r;
    cin >> l >> r;

    for (int j = l; j <= r; j++)
    {
        if (j % 2 == 0 && j > 2)
        {
            cout << j / 2 << " " << j / 2 << endl;
            return;
        }
    }
    if (l == r && l > 7)
    {
        for (int i = 2; i * i <= l; ++i)
        {
            if (l % i == 0)
            {
                cout << l / i << " " << l - l / i << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
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