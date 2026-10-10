#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ll long long
#define ql '\n'
using namespace std;

vector<vector<int>> adj, p;
vector<int> dep;
// log = 20

void dfs(int v, int pai) {
    for (int i = 1; i < 20; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }

    for (int x : adj[v]) {
        if (x == pai) continue;
        p[x][0] = v;
        dep[x] = dep[v] + 1;
        dfs(x, v);
    }
}

int lca(int v, int u) {
    if (dep[v] < dep[u]) swap(v, u);
    int dist = dep[v] - dep[u];

    for (int i = 0; i < 20; i++) {
        if (dist & (1 << i)) v = p[v][i];
    }

    if (v == u) return v;

    for (int i = 19; i >= 0; i--) {
        if (p[v][i] != p[u][i]) {
            v = p[v][i];
            u = p[u][i];
        }
    }

    return p[v][0];
}

int distancia(int v, int u) {
    return dep[v] + dep[u] - 2 * dep[lca(v, u)]; // retorna a distancia entre 2 vertices
}

int binlift(int v, int k) {
    for (int i = 0; i < 20; i++) {
        if (k & (1 << i)) v = p[v][i]; // binary lifting, vertice v pula k vezes pra cima
    }

    return v;
}

void solve() {
    int n, q; cin >> n >> q;
    adj.resize(n + 1);
    dep.resize(n + 1);
    p.resize(n + 1, vector<int>(20));

    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
    }

    dfs(1, 1);

    while(q--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << ql;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t = 1;
    //cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}