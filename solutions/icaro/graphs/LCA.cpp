#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int LOG = 20;
vector<int> adj[N];

int dep[N];
int p[N][LOG];

void dfs_build(int v, int pr){
    for (int i =1; i< LOG; i++){
        p[v][i] = p[p[v][i-1]][i-1];
    }
    for (auto ch : adj[v]){
        if (ch == pr) continue;

        p[ch][0] = v;
        dep[ch] = dep[v] +1;
        dfs_build(ch, v);
    }
}
int lca(int v, int u){
    if (dep[v] < dep[u]) swap(u, v);
    int dist = dep[v] - dep[u];
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
        return p[v][0];
    }
}


