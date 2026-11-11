#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(2 * n + 1);
    vector<ll> dist(n * 2 + 1, 1e18);
    vector<ll> vis(n * 2 + 1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> fila;

    for (int i = 0; i < m; i++) {
        ll x, y, z; cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[x].push_back({y + n, z / 2});
        adj[x + n].push_back({y + n, z});
    }

    fila.push({0, 1});
    dist[1] = 0;
    
    while(!fila.empty()) {
        ll no = fila.top().second;
        fila.pop();
        if (vis[no]) continue;
        vis[no] = 1;
        for (auto[a, b]: adj[no]) {
            if (dist[no] + b < dist[a]) {
                dist[a] = dist[no] + b;
                fila.push({dist[a], a});
            }
        }
    }

    cout << dist[n * 2] << endl;
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

