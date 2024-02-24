#include <bits/stdc++.h>

#define int long long int
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long double ld;

using namespace std;

bool isCross(const vector<string> &b, int i, int j) { return b[i][j] == 'B' && b[i - 1][j - 1] == 'B' && b[i - 1][j + 1] == 'B' && b[i + 1][j - 1] == 'B' && b[i + 1][j + 1] == 'B'; }

int solveBoard(const vector<string> &b, int curi, int curj)
{

    // for (auto x : b)
    //     cout << x << endl;
    // cout << endl;

    vector<vector<int>> freq(7, vector<int>(7, 0));

    for (int i = 1; i < 6; i++)
        for (int j = 1; j < 6; j++)
            if (isCross(b, i, j))
            {
                freq[i][j]++;
                freq[i - 1][j - 1]++;
                freq[i - 1][j + 1]++;
                freq[i + 1][j - 1]++;
                freq[i + 1][j + 1]++;
            }

    int maxFreq = 0, maxI{0}, maxJ{0};

    for (int i = 2; i < 5; i++)
        for (int j = 2; j < 5; j++)
            if (freq[i][j] > maxFreq)
            {
                maxFreq = freq[i][j];
                maxI = i;
                maxJ = j;
            }

    if (maxFreq == 0)
        return 0;

    int minCount = 50;

    for (int i = 2; i < 5; i++)
        for (int j = 2; j < 5; j++)
            if (freq[i][j] > 0 && ((i == curi && j > curj) || i > curi))
            {
                vector<string> newB(7);
                for (int k = 0; k < 7; k++)
                    newB[k] = b[k];
                newB[i][j] = 'W';
                minCount = min(minCount, 1 + solveBoard(newB, i, j));
            }

    return minCount;
}

void solve()
{
    vector<string> board(7);

    for (int i = 0; i < 7; i++)
        cin >> board[i];

    cout << solveBoard(board, 0, 0) << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}