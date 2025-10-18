#include "bits/stdc++.h";
using namespace std;

#define ll long long int

signed main()
{
    int n;
    cin >> n;

    int maxa = -1;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        maxa = max(x, maxa);
    }

    cout << (maxa * maxa * maxa) << endl;
    return 0;
}