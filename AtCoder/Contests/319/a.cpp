#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

// void solve() {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];

//     ll sum_a = 0, cnt_1 = 0;
//     for (int x: a) {
//         sum_a += x;
//         if (x == 1) cnt_1++;
//     }

//     if (sum_a >= cnt_1 + n && n > 1) {
//         cout << "YES" << nl;
//     } else {
//         cout << "NO" << nl;
//     }
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string name;
    cin >> name;

    unordered_map<string, int> map;

    map.insert({"tourist", 3858});
    map.insert({"ksun48", 3679});
    map.insert({"Benq", 3658});
    map.insert({"Um_nik", 3648});
    map.insert({"apiad", 3638});
    map.insert({"Stonefeang", 3630});
    map.insert({"ecnerwala", 3613});
    map.insert({"mnbvmar", 3555});
    map.insert({"newbiedmy", 3516});
    map.insert({"semiexp", 3481});

    cout << map[name] << endl;

    return 0;
}