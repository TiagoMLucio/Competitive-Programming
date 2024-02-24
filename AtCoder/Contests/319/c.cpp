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

    vector<vector<int>> m(3, {0, 0, 0});

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num;
            cin >> num;
            m[i][j] = num;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        vector<int> aux(9, 0);
        for (int j = 0; j < 3; j++) {
            aux[m[i][j]]++;
        }
    }

    return 0;
}