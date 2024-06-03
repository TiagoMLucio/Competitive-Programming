#include <bits/stdc++.h>

#define int long long int
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long double ld;

using namespace std;

void move(char dir, int &x, int &y)
{
    switch (dir)
    {
    case 'L':
        x--;
        break;
    case 'R':
        x++;
        break;
    case 'U':
        y--;
        break;
    case 'D':
        y++;
        break;
    }
}

void solve()
{
    int H, W, N;
    cin >> H >> W >> N;

    string T;

    cin >> T;

    vector<string> S(H);

    for (int i = 0; i < H; i++)
    {
        cin >> S[i];
    }

    int res{0};

    for (int i = 1; i < H - 1; i++)
    {
        for (int j = 1; j < W - 1; j++)
        {
            int y = i, x = j, k = 0;
            while (k < N && S[y][x] != '#')
                move(T[k++], x, y);
            if (k == N && S[y][x] == '.')
                res++;
        }
    }

    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}