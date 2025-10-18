#include "bits/stdc++.h"
using namespace std;

#define int long long int

signed main()
{
    int a;
    cin >> a;

    double r = sqrt(a / M_PI);

    double l = 2 * (r + 1);

    cout << fixed << setprecision(12) << l * l << endl;

    return 0;
}