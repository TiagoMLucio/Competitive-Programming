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
    ll n, x, y;
    cin >> n >> x >> y;
    ll aux = n / lcm(x, y);
    ll n1 = n / x - aux, n2 = n / y - aux;

    ll sum = (2 * n + 1 - n1) * n1 / 2 - (1 + n2) * n2 / 2;

    cout << sum << endl;
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