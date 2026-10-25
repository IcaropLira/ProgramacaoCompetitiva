#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int LOG = 20;
vector<pair<int, int>> adj[N];


int dep[N];
int dep1[N];
int p[N][LOG];

void dfs_build(int v, int pr){
    for (int i = 1; i < LOG; i++){
        p[v][i] = p[p[v][i-1]][i-1];
    }
    for (auto ch : adj[v]){
    if (ch.first == pr) continue;

    p[ch.first][0] = v;
    dep[ch.first] = dep[v] + ch.second;
    dep1[ch.first] = dep1[v] + 1;

    dfs_build(ch.first, v);
}
}
int lca(int v, int u){
    if (dep1[v] < dep1[u]) swap(u, v);
    int dist = dep1[v] - dep1[u];
    for (int i = 0; i< LOG; i++){
        if (dist & (1 << i)){
            v = p[v][i];
        }
    }
    if (v==u) return v;
    for (int i = LOG -1; i >= 0; i--){
        if (p[v][i] != p[u][i]){
            v = p[v][i];
            u = p[u][i];
        }
    }
        return p[v][0];
    }


int subir(int v, int k){
    for (int i = 0; i < LOG; i++){
        if (k & (1 << i)){
            v = p[v][i];
        }
    }
    return v;
}

int query(int v, int u, int k){
    int l = lca(v,u);
    int esq = dep1[v] - dep1[l];
    int dir = dep1[u] - dep1[l];
    if (k <= esq + 1){
        return subir(v, k-1);
    }
    else{
        int total = esq + dir + 1;
        return subir(u, total-k);
    }
}

void solve(){

    int n; cin >> n;

    for (int i = 1; i <= n; i++){
        adj[i].clear();
    }
    for (int i = 1; i<=n-1; i++){
        int u, v, valor; cin >> u >> v >> valor;

        adj[u].push_back({v, valor});
        adj[v].push_back({u, valor});
    }
    dep[1] = 0;
    p[1][0] = 0;
    dfs_build(1,0);
    string op;
    while (cin >> op) {
        if (op == "DONE") {
            break;
        }
        if (op == "DIST"){
            int a, b; cin >> a >> b;
            cout << dep[a] + dep[b] - 2* dep[lca(a,b)] << "\n";
        }
        else {
            int a, b, k; cin >> a >> b >> k;
            cout << query(a, b, k)  << "\n";
        }
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}