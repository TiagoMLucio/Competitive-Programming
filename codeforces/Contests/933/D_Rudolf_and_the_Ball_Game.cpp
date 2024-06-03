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
    int n, m, x;
    cin >> n >> m >> x;

    set<int> s {x};

    for (int i = 0; i < m; i++) {
        int ri;
        cin >> ri;
        char ci;
        cin >> ci;

        set<int> roundS;


        // cout << "teste" << " ";
        // for (auto si: s) {
        //     cout << si << " ";
        // }
        // cout << endl;

        for(auto si: s) {
            if (ci == '0') {
                roundS.insert(1 + (si + ri - 1 + n) % n);
            }
            if (ci == '1') {
                roundS.insert(1 + (si - ri - 1 + n) % n);
            }
            if (ci == '?') {
                roundS.insert(1 + (si + ri - 1 + n) % n);
                roundS.insert(1 + (si - ri - 1 + n) % n);
            }
        }

        s = roundS;
    }

    cout << sz(s) << endl;
    for(auto si: s) cout << si << " ";
    cout << endl;
    
}

signed main()
{

    int T;
    cin >> T;
    while (T--) solve();

    // dbg(time_elapsed());
}