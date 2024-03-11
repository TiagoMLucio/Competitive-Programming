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

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);
    vi b(m);
    for (int i = 0; i < m; i++) cin >> b.at(i);
    
    int res = 0;

    for (auto ai: a) {
        for (auto bi: b) {
            if (ai + bi <= k) res++;
        }
    }
    
    cout << res << endl;
}

signed main()
{

    int T;
    cin >> T;
    while (T--) solve();

    // dbg(time_elapsed());
}