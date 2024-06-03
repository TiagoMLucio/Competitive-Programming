#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string ans;

    vector<int> divs;

    for (int i = 1; i <= 9; i++)
    {
        if (N % i == 0)
            divs.push_back(i);
    }

    for (int i = 0; i <= N; i++)
    {
        char aux = '-';
        for (int div : divs)
        {
            if (i % (N / div) == 0)
            {
                aux = div + '0';
                break;
            }
        }
        ans.push_back(aux);
    }

    cout << ans << endl;

    return 0;
}