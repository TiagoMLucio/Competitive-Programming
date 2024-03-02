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
    int n, l;
    cin >> n >> l;

    ll dist;

    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    dist = 2 * max(a[0], l - a[n - 1]);

    for (int i = 0; i < n; i++)
    {

        dist = max(dist, a[i] - a[i - 1]);
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << dist/2. << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}