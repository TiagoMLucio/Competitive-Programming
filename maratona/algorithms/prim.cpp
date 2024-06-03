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

//A conjunto de arestas
int chave[maxn], adjacente[maxn];
vii arestas;
vii adj[maxn];
int visitados[maxn];

void prim(int inicial) {

    memset(chave, INF, sizeof(chave));
    chave[inicial] = 0;

    priority_queue<ii, vii, greater<ii> > fila;

    fila.push({0, inicial});

    while(!fila.empty()) {
        int menor = fila.top().sc;
        fila.pop();

        if (visitados[menor]) continue;
        visitados[menor] = 1;

        if (menor != inicial) {
            arestas.pb({adjacente[menor], menor});
        }

        for (ii p : adj[menor]) {
            int v = p.fs;
            int w = p.sc;

            if (!visitados[v] && w < chave[v]) {
                adjacente[v] = menor;
                chave[v] = w;
                fila.push({w, v});
            }
        }
    }
}

signed main(){_

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].eb(b, w);
        adj[b].eb(a, w);
    } 

    prim(1);

    cout << sz(arestas) << endl;

    for (ii p : arestas) {
        cout << (char)('a' - 1 + p.fs) << ' ' << (char)('a' - 1 + p.sc) << endl;
    }

    return 0;
}
