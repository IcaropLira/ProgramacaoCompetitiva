#include <algorithm>
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define endl "\n"
using namespace std;
using ll = long long;

void dfs(int no, int pai, vector<vector<pair<int,int>>> &adj, ll d, vector<ll> &dist) {
    dist[no] = d;

    for(auto [a, b] : adj[no]) {
        if(a != pai) {
            dfs(a,no,adj, d + b, dist);
        }
    }
}

void solve() {
    int n; cin >> n; 
    vector<vector<pair<int,int>>> adj(n+1);
    ll somaArestas = 0;

    for(int i = 1; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        somaArestas += c;
    }

    vector<ll> dist1(n+1);
    vector<ll> dist2(n + 1);
    dfs(1, -1, adj, 0, dist1);

    auto it = max_element(all(dist1));

    dfs(it - dist1.begin(), -1, adj, 0, dist2);

    ll maiorDist = *max_element(all(dist2));

    cout << 2 * somaArestas - maiorDist << endl;

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

