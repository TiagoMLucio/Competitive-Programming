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
    int n, k;
    cin >> n >> k;

    string s;

    cin >> s;

    unordered_map<char, int> char_count;

    for (char c : s)
    {
        char_count[c]++;
    }

    int odd = 0, even = 0;

    for (auto pic : char_count)
    {
        if (pic.second % 2 == 0)
            even++;
        else
            odd++;
    }

    if (k >= odd - 1)
    {
        cout << "YES" << nl;
    }
    else
    {
        cout << "NO" << nl;
    }
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