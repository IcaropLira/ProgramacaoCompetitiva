#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int LOG = 20, N = 2e5 + 10;

int dep[N];
int depnivel[N];
int p[N][LOG];
vector<vector<pair<int, int>>> adj;

void dfs_build(int v, int c, int pr = -1, int d = 1) {
    dep[v] = c;
    depnivel[v] = d;
    for(int i = 1; i < LOG; i++) {
        p[v][i] = p[p[v][i-1]][i-1];
    }

    for(auto& [fi,peso] : adj[v]) {
        if(fi == pr) continue;
        p[fi][0] = v;
        dfs_build(fi,peso + c,v,d + 1);
    }
}

int lca(int v, int u) {
    if(depnivel[v] < depnivel[u]) swap(v,u);

    int dist = depnivel[v] - depnivel[u];

    for(int i = 0; i < LOG; i++) {
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

int dist(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a,b)];
}

int distprofundidade(int a, int b) {
    return depnivel[a] + depnivel[b] - 2 * depnivel[lca(a,b)];
}

int kth(int a, int b, int k) {
    int ancestralcomum = lca(a,b);
    if(k == distprofundidade(a,ancestralcomum)) return ancestralcomum;
   
    else if(k < distprofundidade(a,ancestralcomum)) {
        for(int i = 0; i < LOG; i++) {
            if(k & ( 1 << i)) {
                a = p[a][i];
            }
        }
        return a;
    }

    else {
        int distFinal = distprofundidade(b, ancestralcomum) - (k - distprofundidade(a, ancestralcomum));
        for(int i = 0; i < LOG; i++) {
            if(distFinal & (1 << i)) {
                b = p[b][i];
            }
        }
        return b;
    }
}


void solve() {
    int n; cin >> n;
    adj.resize(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dfs_build(1, 0);

    while(1) {
        string type; cin >> type;
        if(type == "DIST") {
            int a, b; cin >> a >> b;
            cout << dist(a,b) << endl;
        }

        else if(type == "KTH") {
            int a, b, k; cin >> a >> b >> k;
            cout << kth(a,b,k - 1) << endl;
        }

        else break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        adj.clear();
        solve();
    }

    return 0;
}

