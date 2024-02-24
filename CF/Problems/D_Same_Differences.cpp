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

    map<int, int> freqs;

    for (int i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
        freqs[aux - i]++;
    }

    int pairs{0};

    for (auto freq : freqs)
    {
        int aux = freq.second;
        if (aux > 1)
            pairs += aux * (aux - 1) / 2;
    }

    cout << pairs << endl;
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