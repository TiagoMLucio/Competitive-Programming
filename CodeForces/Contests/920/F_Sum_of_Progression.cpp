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

    ll n, q;

    cin >> n >> q;

    vector<ll> a(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (q--)
    {
        ll s, d, k;
        cin >> s >> d >> k;

        ll sum{0};

        for (size_t i = s, j = 1; j <= k; i += d, j++)
        {
            sum += a[i - 1] * j;
        }

        cout << sum << " ";
    }

    cout << endl;
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