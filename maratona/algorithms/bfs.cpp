#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

#define maxn 112345

vi adj[maxn];

void bfs(int node){
    queue<int> fila;

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        for(int v : adj[u]){
            if(!vis[u]){
                vis[u] = 1;
                fila.push(u);
            }
        }
    }
}

signed main(){_

    return 0;
}
