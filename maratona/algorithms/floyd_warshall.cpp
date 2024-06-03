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
#define maxn 1123

using namespace std;

int dist[maxn][maxn];
int n;

void floyd_warshall(void){
    for(int k=1; k<=n; k++){ // vertice intermediário
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(d[i][j], d[i][k] + d[k][j] );
            }
        }
    }
}

signed main(){_

    memset(dist, INF, sizeof(dist));
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, peso;
        cin >> a >> b >> peso;

        dist[a][b] = peso;
        dist[b][a] = peso;
    }

    floyd_warshall();



    return 0;
}
