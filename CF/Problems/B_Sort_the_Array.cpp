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
    size_t n;
    cin >> n;

    int monotonic{0}, l{n - 1}, r{n - 1};

    vector<int> a(n);

    for (size_t i{0}; i < n; i++)
        cin >> a[i];

    for (size_t i{0}; i < n - 1; i++)
    {
        if (monotonic % 2 == 0 && a[i] > a[i + 1])
        {
            monotonic++;
            l = i;
        }
        else if (monotonic % 2 == 1 && a[i] < a[i + 1])
        {
            monotonic++;
            r = i;
        }
    }

    bool yes{monotonic == 0 || (monotonic <= 2 && (l == 0 || a[l - 1] < a[r]) && (r == n - 1 || a[l] < a[r + 1]))};

    cout << (yes ? "yes" : "no") << endl;
    if (yes)
        cout << l + 1 << " " << r + 1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}