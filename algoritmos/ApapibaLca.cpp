#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
const int LOG = 20, N = 3e5 + 10;

int dep[N];
int p[N][LOG];
vector<vector<int>> adj;

void dfs_build(int v, int pr = -1, int d = 1) {
    dep[v] = d;

    for(int i = 1; i < LOG; i++) p[v][i] = p[p[v][i-1]][i-1];

    for(int fiote : adj[v]) {
        if(fiote == pr) continue;
        p[fiote][0] = v;
        dfs_build(fiote, v, d + 1);
    }
}

int lca(int u, int v) {
    if(dep[v] < dep[u]) swap(u,v);

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

int distancia(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a,b)];
}


int jump(int u, int v, int k) {
   int distlca = distancia(u,lca(u,v));
   int ancestral = lca(u,v);

   if(k >= distancia(u,v)) return v;

   if(k == distlca) return ancestral;

   else if(k < distlca) {
       for(int i = 0; i < LOG; i++) {
            if(k & (1 << i)) {
                u = p[u][i];
            }
        }
       return u;
   }

   else {
    int distlca2 = distancia(v,lca(u,v));
    int distFinal = distlca2 - (k - distlca);

    for(int i = 0; i < LOG; i++) {
        if(distFinal & (1 << i)) {
            v = p[v][i];
        }
    }
    return v;
   }
    
}


void solve() {
    int n; cin >> n;
    
    adj.resize(n + 1);

    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_build(1);
    int q; cin >> q;

    while(q--) {
        int x, y, z; cin >> x >> y >> z;

        cout << jump(x,y,z) << endl;
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

