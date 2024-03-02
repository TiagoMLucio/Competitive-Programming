    #include <bits/stdc++.h>
     
    #define int long long int
    #define all(x) (x).begin(), (x).end()
    #define allr(x) (x).rbegin(), (x).rend()
    #define gsize(x) (int)((x).size())
     
    const char nl = '\n';
    typedef long double ld;
     
    using namespace std;
     
    vector<string> board(7);
     
    bool isCross(int i, int j) { 
        return board[i][j] == 'B' && board[i - 1][j - 1] == 'B' && board[i - 1][j + 1] == 'B' && board[i + 1][j - 1] == 'B' && board[i + 1][j + 1] == 'B'; 
    }
     
    void solve()
    {
        for (int i = 0; i < 7; i++)
            cin >> board[i];
     
        bool done{false};
     
        int count{0};
     
        while (!done)
        {
            // for (int i = 0; i < 7; i++)
            // {
            //     cout << board[i] << endl;
            // }
            // cout << endl;
     
            vector<vector<int>> freq(7, vector<int>(7, 0));
     
            for (int i = 1; i < 6; i++)
                for (int j = 1; j < 6; j++)
                {
                    if (isCross(i, j))
                    {
                        freq[i][j]++;
                        freq[i - 1][j - 1]++;
                        freq[i - 1][j + 1]++;
                        freq[i + 1][j - 1]++;
                        freq[i + 1][j + 1]++;
                    }
                }
     
            int maxFreq = 0, maxI{0}, maxJ{0};
     
            for (int i = 0; i < 7; i++)
                for (int j = 0; j < 7; j++)
                {
                    if (freq[i][j] > maxFreq)
                    {
                        maxFreq = freq[i][j];
                        maxI = i;
                        maxJ = j;
                    }
                }
     
            // cout << "maxFreq: " << maxFreq << endl;
     
            if (maxFreq > 0)
            {
                board[maxI][maxJ] = 'W';
                count++;
            }
            else
                done = true;
        }
     
        cout << count << endl;
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