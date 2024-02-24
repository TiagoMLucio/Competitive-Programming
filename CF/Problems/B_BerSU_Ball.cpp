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
    int n, m;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m;

    vector<int> b(m);

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    int i = 0, j = 0;

    int count{0};

    while (i < n && j < m)
    {
        if (a[i] > b[j] + 1)
            j++;
        else if (a[i] < b[j] - 1)
            i++;
        else
        {
            count++;
            i++;
            j++;
        }
    }

    cout << count << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}