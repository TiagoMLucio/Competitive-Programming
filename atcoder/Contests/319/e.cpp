#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

#define int ll

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;

    cin >> n >> x >> y;

    vector<int> p(n - 1, 0), t(n - 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int pi, ti;
        cin >> pi >> ti;
        p[i] = pi;
        t[i] = ti;
    }

    vector<int> res(840, 0);

    for (int i = 0; i < 840; i++)
    {
        int q = i;
        q += x;
        for (int i = 0; i < n - 1; i++)
        {
            int r = q % p[i];
            if (r != 0)
                q += p[i] - r;
            q += t[i];
        }

        q += y;

        res[i] = q - i;
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int q;
        cin >> q;
        cout << q + res[q % 840] << endl;
    }

    return 0;
}