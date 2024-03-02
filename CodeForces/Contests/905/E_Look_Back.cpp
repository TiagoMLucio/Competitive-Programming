#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define int ll

using namespace std;

void solve()
{
    size_t n;
    cin >> n;

    vector<int> a(n);
    vector<int> p(n, 0);

    int ans = 0;

    for (size_t i = 0; i < n; i++)
        cin >> a[i];

    for (size_t i = 1; i < n; i++)
    {
        int prev = a[i - 1];
        int cur = a[i];
        int paux = p[i - 1];

        while (paux && prev <= cur)
        {
            paux--;
            prev *= 2;
        }

        p[i] += paux;

        while (cur < prev)
        {
            cur *= 2;
            p[i]++;
        }

        ans += p[i];
    }

    // cout << "P: " ;
    // for (auto pi: p) {
    //     cout << pi << ", ";
    // }
    // cout << endl;

    cout << ans << endl;
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