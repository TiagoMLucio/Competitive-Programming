#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    multiset<int> lset, rset;

    while (q--)
    {
        char op;

        cin >> op;

        int l, r;

        cin >> l >> r;

        if (op == '+')
        {
            lset.insert(l);
            rset.insert(r);
        }
        else
        {
            lset.erase(lset.find(l));
            rset.erase(rset.find(r));
        }

        if (lset.empty() || *lset.rbegin() <= *rset.begin())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}