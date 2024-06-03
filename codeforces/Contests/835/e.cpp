#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (ll)((x).size())
#define int ll

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

ll n, a[112345], tree[4 * 112345];

void build(ll node, ll left, ll right)
{
    if (left > right)
        return;
    if (left == right)
    {
        tree[node] = a[left];
        return;
    }

    ll mid = left + (right - left) / 2;
    build(2 * node, left, mid);
    build(2 * node + 1, mid + 1, right);
    tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    return;
}

ll sum(ll node, ll left, ll right, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == left and r == right)
        return tree[node];
    ll mid = left + (right - left) / 2;
    return sum(2 * node, left, mid, l, min(r, mid)) ^ sum(2 * node + 1, mid + 1, right, max(l, mid + 1), r);
}

void solve()
{
    cin >> n;

    string s;

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll xor0{0}, xor1{0};

    cin >> s;

    build(1, 0, n - 1);

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
            xor0 ^= a[i];
        else
            xor1 ^= a[i];
    }

    ll q;
    cin >> q;

    while (q--)
    {
        ll tp;
        cin >> tp;
        if (tp == 1)
        {
            ll l, r;
            cin >> l >> r;

            ll aux = sum(1, 0, n - 1, l - 1, r - 1);
            xor1 ^= aux;
            xor0 ^= aux;
        }
        else
        {
            ll g;
            cin >> g;
            cout << (g == 1 ? xor1 : xor0) << " ";
        }
    }

    cout << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}