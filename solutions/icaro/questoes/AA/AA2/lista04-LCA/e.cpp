#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5+5;
const int LOG = 20;
vector<int> adj[N];

int p[N][LOG];
int dep[N];
ll ans[N];



void dfs(int v, int pr){
    for (int i  = 1; i< LOG; i++){
        p[v][i] = p[p[v][i-1]][i-1];
    }
    for (auto ch: adj[v]){
        if (ch == pr) continue;
        dep[ch] = dep[v] + 1;
        p[ch][0] = v;
        dfs(ch, v);
    }
}

int lca(int v, int u){
    if (dep[v] < dep[u]) swap(v, u);
    int dist = dep[v] - dep[u];
    for (int i = 0; i < LOG; i++){
        if (dist & (1 << i)) v = p[v][i];
    }
    if (v== u) return v;
    for ( int i = LOG-1; i >= 0; i--){
        if (p[v][i] != p[u][i]){
            v  = p[v][i];
            u = p[u][i];
        }
    }
        return p[v][0];
}
        


void soma(int v, int p){
    for (int u : adj[v]){
        if (u == p) continue;
        soma(u,v);
        ans[v] += ans[u];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        int l = lca(a,b);
        ans[a]++;
        ans[b]++;
        ans[l]--;
        if (p[l][0] != 0){
            ans[p[l][0]]--;
        }
    }
    soma(1,0);

    for (int i = 1; i<= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    

    return 0;
}

