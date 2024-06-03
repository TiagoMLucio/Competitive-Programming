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

    std::map<std::string, int> freq;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        if (freq[name]++ == 0)
            cout << "OK" << endl;
        else
            cout << name << freq[name] - 1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}