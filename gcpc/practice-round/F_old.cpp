#include "bits/stdc++.h"
using namespace std;

#define int long long int

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> connections(n - 1);

    for (int j = 0; j < m; j++)
    {
        int i, d, c;
        cin >> i >> d >> c;
        connections.at(i - 1).push_back({c, d});
    }

    int q;
    cin >> q;
    vector<pair<int, int>> w(q);
    for (int i = 0; i < q; i++) {
        int wi;    
        cin >> wi;
        w.at(i) = {wi, i};
    }

    for (auto &connection : connections)
        sort(connection.begin(), connection.end(), greater<pair<int, int>>());
    sort(w.begin(), w.end(), greater<pair<int, int>>());

    // for (int i = 0; i < n - 1; i++)
    // {
    //     cout << "city i=" << i << endl;
    //     for (auto path : connections.at(i))
    //     {
    //         cout << "c, d = " << path.first << ", " << path.second << endl;
    //     }
    // }

    // for (auto wi : w)
    //     cout << wi << " ";
    // cout << endl;

    vector<int> idx(n - 1, -1), best_idx(n - 1, -1);

    int time;

    vector<pair<int, int>> results(q);

    for (int c = 0; c < q; c++)
    {
        time = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = idx.at(i) + 1; j < connections.at(i).size(); j++)
            {
                if (connections.at(i).at(j).first >= w.at(c).first)
                {
                    idx.at(i) = j;
                    if (best_idx.at(i) == -1 || connections.at(i).at(j).second <= connections.at(i).at(best_idx.at(i)).second)
                        best_idx.at(i) = j;
                } else break;
            }
            if (best_idx.at(i) == -1)
            {
                results.at(c) = {w.at(c).second, -1};
                goto next_car;
            }
            else
                time += connections.at(i).at(best_idx.at(i)).second;
        }

        results.at(c) = {w.at(c).second, time};

        next_car:
        continue;
    }

    sort(results.begin(), results.end());

    for(auto res: results) {
        if(res.second == -1) 
            cout << "impossible";
        else cout << res.second;
        cout << endl;
    }

    return 0;
}