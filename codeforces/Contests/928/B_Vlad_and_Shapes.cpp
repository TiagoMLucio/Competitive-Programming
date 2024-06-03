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
    int n;
    cin >> n;

    int maxones{0}, ones{0};

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;

        int lineOnes{0};

        for (auto c : line)
            if (c == '1')
                lineOnes++;

        ones += lineOnes;
        maxones = max(maxones, lineOnes);
    }

    cout << (maxones * maxones == ones ? "SQUARE" : "TRIANGLE") << endl;
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