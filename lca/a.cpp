#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj, p;
vector<int> dep;
const int LOG = 20;

void a(){
    
}

void build(int v, int pai){
    for (int i = 1; i < LOG; i++){
        p[v][i] = p[p[v][i - 1]][i - 1];
    }
    for (int ch: adj[v]){
        if (ch == pai) continue;
        p[ch][0] = v;
        dep[ch] = dep[v] + 1;
        build(ch, v);
    }
}

int lca(int v, int u){
    if (dep[v] < dep[u]) swap(v, u);
    int dist = dep[v] - dep[u];

    for (int i = 0; i < LOG; i++){
        if (dist & (1 << i)) v = p[v][i];
    }

    if (v == u) return v;

    for(int i = LOG - 1; i >= 0; i--){
        if (p[u][i] != p[v][i]){
            v = p[v][i];
            u = p[u][i];
        }
    }

    return p[v][0];
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    dep.resize(n + 1);
    p.resize(n+1, vector<int>(20));

    for (int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[x].push_back(i);
    }

    build(1, 1);

    while (m--){
        int x, y; cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
