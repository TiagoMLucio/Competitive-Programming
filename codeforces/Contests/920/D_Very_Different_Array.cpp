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
    size_t n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);

    ll D{0};

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (size_t i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    size_t a_p1{0}, a_p2{n - 1};
    size_t b_p1{0}, b_p2{m - 1};

    for (size_t i = 0; i < n; i++)
    {
        size_t a_p = max(abs(a[a_p1] - b[b_p1]), abs(a[a_p1] - b[b_p2])) > max(abs(a[a_p2] - b[b_p1]), abs(a[a_p2] - b[b_p2])) ? a_p1++ : a_p2--;
        D += abs(a[a_p] - b[b_p1]) < abs(a[a_p] - b[b_p2]) ? abs(a[a_p] - b[b_p2--]) : abs(a[a_p] - b[b_p1++]);
    }

    cout << D << endl;
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