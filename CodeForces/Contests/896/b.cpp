#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

#define int ll

using namespace std;

int f(pair<int, int> c1, pair<int, int> c2)
{
    return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}

void solve()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    vector<pair<int, int>> points;

    for (int i = 0; i < n; i++)
    {
        int xi, yi;
        cin >> xi >> yi;
        points.push_back({xi, yi});
    }

    pair<int, int> start = points[a - 1];
    pair<int, int> end = points[b - 1];


    int ans = f(start, end);
    int ans_start{ans};
    int ans_end{ans};

    for (int i = 0; i < k; i++)
    {
        pair<int, int> major = points[i];
        ans_start = min(ans_start, f(start, major));
        ans_end = min(ans_end, f(end, major));
    }


    ans = min(ans, ans_start + ans_end);

    cout << ans << endl;
    return;
}

signed main()
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