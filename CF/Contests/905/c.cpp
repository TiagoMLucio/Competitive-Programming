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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = k;
    int even = 0, odd = 0;

    for (auto ai : a)
    {
        if (ai % k == 0)
        {
            ans = 0;
            break;
        }
        if (ai % 2 == 0)
            even++;
        else
            odd++;

        ans = min(ans, k - ai % k);
    }

    if (k == 4)
    {
        int aux = k;
        if (even >= 2)
            aux = 0;
        else if (even == 1 && odd >= 1)
            aux = 1;
        else if (even == 0 && odd >= 2)
            aux = 2;
        ans = min(ans, aux);
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