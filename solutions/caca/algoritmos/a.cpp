#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
const int LOG = 20, N = 2e5 + 10;

int n;
int p[N][LOG];
int dep[N];
vector<vector<int>> adj(n + 1);

void dfs_build(int v, int pr = -1, int d = 1) {
    dep[v] = d;
    for(int i = 1; i < LOG; i++) {
        p[v][i] = p[p[v][i-1]][i-1];
    }

    for(int ch : adj[v]) {
        if(ch == pr) continue;
        p[ch][0] = v;
        dfs_build(ch, v, d + 1);
    }
}

int lca(int u, int v) {
    if(dep[v] < dep[u]) swap(u,v);

    int dist = dep[v] - dep[u];
    for(int i = 0; i < LOG; i++){
        if(dist & (1 << i)) {
            v = p[v][i];
        }
    }

    if(u == v) return v;

    for(int i = LOG - 1; i >= 0; i--) {
        if(p[v][i] != p[u][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[v][0];
}

int jump(int v, int k) {
    for(int i = 0; i < LOG; i++) {
        if(k & (1 << i)) {
            v = p[v][i];
        }
    }
    return v;
}

void solve() {
    int n, q; cin >> n >> q;
    adj.resize(n + 1);
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
    }
    
    dfs_build(1);
    while(q--) {
        int a, b; cin >> a >> b;
        int resp = jump(a,b);
        if(resp == 0) resp = -1;
        cout << resp  << endl;        
    }


}

int main() {

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}

