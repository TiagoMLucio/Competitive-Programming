#include "bits/stdc++.h"
using namespace std;

#define fori(n) for(int i = 0; i < n; i++)
#define sz(x) static_cast<int>((x).size())
#define endl '\n'
# define int long long

template<class T> using V = vector<T>;
using vi = V<int>;
using vvi = V<vi>;
using vb = V<bool>;

bool dfs(int v, bool isRed, int pi, const vvi& adj, vb& used, vb& reds) {
    used.at(v) = true;
    if (isRed) reds.at(v) = true;

    for(auto u: adj.at(v)) if (u != pi) {
        if (used.at(u) && reds.at(u) == isRed) return false;
        else if (!used.at(u) && !dfs(u, !isRed, v, adj, used, reds)) return false;
    }
    
    return true;
}

bool isBipartite(const vvi& graph) {
    int n = sz(graph);
    vb used(n);
    vb reds(n);
    fori(n) 
        if (!used.at(i) && !dfs(i, true, -1, graph, used, reds)) 
            return false;
    return true;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vvi graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    cout << (isBipartite(graph) ? "True" : "False") << endl;
}   