#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        ll root = sqrt(a);
        cout << (root * root == a && isPrime(root) ? "YES" : "NO") << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}