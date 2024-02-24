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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll sum_a = 0, cnt_1 = 0;
    for (int x : a)
    {
        sum_a += x;
        if (x == 1)
            cnt_1++;
    }

    if (sum_a >= cnt_1 + n && n > 1)
    {
        cout << "YES" << nl;
    }
    else
    {
        cout << "NO" << nl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    multiset<pair<int, int>> mset;

    multiset<pair<int, int>, greater<int>>::iterator itr;

    pair<int, int> intersec = {0, 1e9};

    while (q--)
    {
        char op;

        cin >> op;

        int l, r;

        cin >> l >> r;

        if (op == '+')
        {
            mset.insert({l, r});
            intersec = {max(intersec.first, l), min(intersec.second, r)};
        }
        else
        {
            mset.erase(mset.find({l, r}));

            intersec = {0, 1e9};

            for (itr = mset.begin(); itr != mset.end(); ++itr)
            {
                intersec = {max(intersec.first, itr->first), min(intersec.second, itr->second)};
            }
        }

        if (intersec.first > intersec.second)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}