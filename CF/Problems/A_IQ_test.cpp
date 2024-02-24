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

    ll amount_odd{0}, amount_even{0};
    ll odd_idx{0}, even_idx{0};

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (a % 2 == 0)
        {
            amount_odd++;
            odd_idx = i +1;
        }
        else
        {
            amount_even++;
            even_idx = i + 1;
        }
    }

    cout << (amount_odd == 1 ? odd_idx : even_idx) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}