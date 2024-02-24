#include <bits/stdc++.h>

#define int long long int
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long double ld;

using namespace std;

int findFirstGE(const std::vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int result = arr.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

void solve()
{
    int n, m;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0)
        {
            a[i] += a[i - 1];
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        cout << findFirstGE(a, q) + 1 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}