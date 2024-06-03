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
using namespace std;

vi adj[maxn];
int grau[maxn];
int resp[maxn];

signed main(){_

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;

        grau[b]++;
        adj[a].pb(b);
    }

    for(int i=1; i<=n; i++) if(grau[i]==0) resp.pb(i);

    int ptr = 0;
    while(ptr < sz(resp)){
        int atual = resp[ptr];
        ptr++;

        for(int x : adj[atual]){
            grau[x]--;
            if(grau[x] == 0) lista.pb(x);
        }
    }   

    return 0;
}
