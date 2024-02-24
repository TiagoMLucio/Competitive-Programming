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
    string s;
    cin >> s;

    for (auto i = 0; i < s.length(); i++)
    {
        s[i] -= '0';
    }

    s[0] = (9 - s[0] < s[0] && s[0] != 9) ? 9 - s[0] : s[0];

    for (int i = 1; i < s.length(); i++)
        s[i] = (9 - s[i] < s[i]) ? 9 - s[i] : s[i];

    for (auto i = 0; i < s.length(); i++)
    {
        s[i] += '0';
    }

    cout << s << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}