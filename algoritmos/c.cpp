#include <bits/stdc++.h>
#define all(v) v.begin(), v.end();
using namespace std;

using ll = long long;
const int LOG = 20, N = 2e5 + 10; 

int n;
vector<vector<int>> adj(n + 1);
int p[N][LOG];
int dep[N];

void dfs_build(int v, int pr = 1, int d = 1)  {
    dep[v] = d;
    for(int i = 1; i < LOG; i++) {
        p[v][i] = p[p[v][i-1]][i-1];
    }

    for(int fi : adj[v]) {
        if(fi == pr) continue;
        p[fi][0] = v;
        dfs_build(fi, v, d + 1);
    }

}

int lca(int v, int u) {
    if(dep[v] < dep[u]) swap(v,u);

    int dist = dep[v] - dep[u];

    for(int i = 0; i < LOG; i++) {
        if(dist & (1 << i)) {
            v = p[v][i];        
        }
    }
    if(u == v) return v;

    for(int i = LOG - 1; i >= 0; i--) {
        if(p[v][i] != p[u][i]) {
            v = p[v][i];
            u = p[u][i];
        }
    }
    return p[v][0];
}


int dist(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a,b)];
}

void solve() {
    int q; cin >> n >> q;
    adj.resize(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_build(1);

    while(q--) {
        int x, y; cin >> x >> y;
        cout << dist(x,y) << endl;
    }  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}

