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
    int m, s;
    cin >> m >> s;

    if ((s == 0 && m > 1) || s > m * 9)
    {
        cout << "-1 -1" << endl;
        return;
    }

    string menor, maior;

    int aux = s - 1;

    for (int i = 0; i < m - 1; i++)
    {
        int dig = (aux > 9) ? 9 : aux;
        aux = max(aux - dig, 0LL);
        menor += '0' + dig;
    }
    menor += '0' + aux + 1;

    aux = s;

    for (int i = 0; i < m; i++)
    {
        int dig = (aux > 9) ? 9 : aux;
        aux = max(aux - dig, 0LL);
        maior += '0' + dig;
    }

    reverse(all(menor));

    cout << menor << " " << maior << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}