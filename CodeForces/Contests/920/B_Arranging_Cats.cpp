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
    int n, f, a, b;
    cin >> n >> f >> a >> b;

    string s, f;

    cin >> s >> f;

    int missing{0}, extra{0};

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && f[i] == '0')
            extra++;
        else if (s[i] == '0' && f[i] == '1')
            missing++;
    }

    cout << max(extra, missing) << endl;
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