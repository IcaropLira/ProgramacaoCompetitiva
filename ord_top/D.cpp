#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<ll> in(n + 1), ant(n + 1, 0), dist(n + 1, 1e9), vis(n + 1, 0), pred(n + 1, 0);
    priority_queue<pair<int, int>> fila;

    for (int i = 0; i < m; i++) {
        int x, y, k; cin >> x >> y >> k;
        adj[x].push_back({y, k});
        in[y] += 1;
    }

    fila.push({0, 1});
    
    ant[1] = 1;
    dist[1] = 0;
    ll mini = 1e9;
    ll maxi = 1;

    while (!fila.empty()) {
        int top = fila.top().second;
        fila.pop();
        if (vis[top]) continue;
        vis[top] = 1;
        for (pair<int, int> ch: adj[top]) {
            if (dist[ch.first] > dist[top] + ch.second) {
                dist[ch.first] = dist[top] + ch.second;
                ant[ch.first] = ant[top];
                fila.push({-dist[ch.first], ch.first});
                mini = pred[top] + 1;
                maxi = pred[top] + 1;
            } else if (dist[ch.first] == dist[top] + ch.second) {
                ant[ch.first] = (ant[ch.first] + ant[top]) % mod;
                mini = min(pred[top] + 1, mini);
                maxi = max(pred[top] + 1, maxi);
            }
        }
    }
    cout << dist[n] << " " << ant[n] << " " << mini << " " << maxi << endl;

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

