#include "bits/stdc++.h"
using namespace std;

#define int long long int

signed main()
{
    string action;
    cin >> action;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (action == "encrypt")
            for (auto &c : s)
                c = c == 'z' ? 'a' : c + 1;
        else
            for (auto &c : s)
                c = c == 'a' ? 'z' : c - 1;
        cout << s << endl;
    }

    return 0;
}