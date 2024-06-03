#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    string pin;

    cin >> pin;
    
    ll ans = 0;

    ll prev = 1, cur = 0;

    for (int i = 0; i < 4; i++) {
        cur = pin.at(i) - '0';
        cur = cur == 0 ? 10 : cur;
        ans += abs(cur - prev) + 1;
        prev = cur;
    } 

    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}