#include "bits/stdc++.h"
#include <chrono>
using namespace std;

using ll = long long;
using ld = long double;
using str = string;

#define sz(x) static_cast<int>((x).size())
#define MAXX 1073741823
#define MAX (1 << 20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define endl '\n'
#define int ll

using ii = pair<int, int>;
#define mp make_pair
#define f first
#define s second

using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;

using vi = vector<int>;
using vii = vector<ii>;
using viii = vector<iii>;
using viiii = vector<iiii>;
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()


int n, m, k, d;
int a[3123456];
int acc[3123456];

int dp(int j) {
    if (j <= 0) return 1;
    if (acc[j] > 0) return acc[j];
    
    int minDist = INF;

    for (int i = d + 1; i >= 1; i--)
        minDist = min(minDist, dp(j - i));

    int res = a[j] + 1 + minDist;

    acc[j] = res;

    return res;
}

void solve()
{
    cin >> n >> m >> k >> d;
    vi dist(n);

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            acc[j] = 0; 
            cin >> a[j];
        }
        dist.at(i) = dp(m - 1);
    }

    int curDist = 0;

    for (int j = 0; j < k; j++)
        curDist += dist.at(j);

    int minTotalDist = curDist;
    
    for (int i = 1; i < n - k + 1; i++) {
        curDist += dist.at(i + k - 1) - dist.at(i - 1) ;
        minTotalDist = min(minTotalDist, curDist);
    }

    cout << minTotalDist << endl;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) solve();

    // dbg(time_elapsed());
}