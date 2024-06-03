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
#define maxn 11234
#define maxl 40

using namespace std;

vi adj[maxn];
int pai[maxn];
int nivel[maxn];
int ancestral[maxl][maxl];

void dfs(int node){
    for (int x : adj[node]){
        if(nivel[x] == -1){
            pai[x] = node;
            nivel[x] = nivel[node] + 1;
            dfs(x);
        }
    }
}

void ancestrais(){
    memset(ancestral, -1, sizeof(ancestral));

    for(int i=1; i<=n; i++) ancestral[i][0] = pai[i];

    for(int j=1; j<maxl; j++){
        for(int i=1; i<=n; i++){
            if(ancestral[i][j-1] != -1){
                ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
            }
        }
    }
}

int lca(int u, int v){
    if(nivel[u] < nivel[v]) swap(u, v);

    //Fazendo com que nivel[u] == nivel[v]
    for(int i=maxl-1; i>=0; i--){
        if(nivel[u] - (1<<i) >= nivel[v]){
            u = ancestral[u][i];
        }
    }

    if(u==v) return u;

    for(int i= maxl -1; i>=0; i--){
        if(ancestral[u][i]!= -1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }

    return ancestral[u][0];

}

signed main(){_



    return 0;
}
