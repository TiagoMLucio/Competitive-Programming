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
#define maxm 200200
#define maxn 50500

using namespace std;

struct aresta{
    int peso;
    int a, b;
};

bool comp(aresta a, aresta b){
    return a.peso < b.peso;
}

int n, m;
aresta arestas[maxm];
int pai[maxn];
int peso[maxn];
aresta mst[maxm]; //Aqui guardaremos a arvore

int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    a = pai[a];
    b = pai[b];

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[a] < peso[b]) pai[a] = b;
    else {
        pai[b] = a;
        peso[a]++;
    }
}

void kruskal(){
    cout << m << endl;
    for (int i = 1; i <= n; i++) pai[i] = i;

    sort(arestas+1, arestas+1+m, comp);

    int size = 0;

    for (int i=1; i<=m; i++) {
        int a = arestas[i].a;
        int b = arestas[i].b;
        if(find(a) != find(b)){
            join(a,b);

            mst[++size] = arestas[i];
            if(size==n-1) return;
        }
    }
}

signed main(){_

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        arestas[i].peso = w;
        arestas[i].a = u;
        arestas[i].b = v;
    }

    cout << m << endl;
    kruskal();

    for (int i = 1; i < n; i++) {
        cout << mst[i].a << ' ' << mst[i].b << endl;
    }

    return 0;
}
