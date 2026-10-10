#include <algorithm>
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

using ll = long long;

void dfs(int no, int pai, vector<vector<pair<int,int>>> &adj, vector<ll> &dist, ll d) {
    dist[no] = d;

    for(auto [a, b] : adj[no]) {
        if(a != pai) {
            dfs(a, no,adj, dist, d + b);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<pair<int,int>>> adj(n+ 1);

    ll somaArestas = 0;
    
    for(int i = 1; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        somaArestas += c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }


    vector<ll> dist(n + 1);
    dfs(1, -1, adj, dist, 0);

    ll maiorDist = *max_element(all(dist));

    cout << 2 * somaArestas - maiorDist << endl;
}

int main() {
    
    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}

