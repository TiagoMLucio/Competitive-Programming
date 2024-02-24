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
    int n;
    cin >> n;
    int ans{-1};
    for (int i = 0; i < n; i++)
    {
        int d, s;
        cin >> d >> s;
        if (ans == -1)
            ans = d + (s - 1) / 2;
        else
            ans = min(ans, d + (s - 1) / 2);
    }
    cout << ans << endl;
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