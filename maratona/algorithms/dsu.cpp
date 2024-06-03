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

int pai[maxn];
int peso[maxn];

int find(int x){
    if(pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if(a==b) return;

    if(peso[a] > peso[b]) pai[b] = a;
    if(peso[a] < peso[b]) pai[a] = b;
    if(peso[a] ==peso[b]){
        pai[a] = b;
        peso[b]++;
    }

    // pai[a] = b;
}

signed main(){_

    return 0;
}
