#include <bits/stdc++.h>
using namespace std;

using ll = long long;

long long menorCaminho(const vector<vector<pair<ll,ll>>>& lista) {
    ll n = lista.size() - 1;
    vector<vector<pair<ll,ll>>> adj(2 * n + 1);

    auto liga = [&](ll a, ll b, long long k) {
        if (k == 0) {
            adj[a].push_back({b, 0});
            return;
        }
        ll ant = a;
        for (long long i = 0; i < k - 1; i++) {
            adj.push_back({});
            ll novo = adj.size() - 1;
            adj[ant].push_back({novo, 1});
            ant = novo;
        }
        adj[ant].push_back({b, 1});
    };

    for (ll u = 1; u <= n; u++) {
        for (auto [v, c] : lista[u]) {
            liga(u, v, c);          // camada 0, sem desconto
            liga(u + n, v + n, c);  // camada 1, sem desconto
            liga(u, v + n, c / 2);  // usa o desconto
        }
    }

    const long long INF = LLONG_MAX;
    vector<long long> dist(adj.size(), INF);
    dist[1] = 0;
    deque<ll> fila;
    fila.push_back(1);

    while (!fila.empty()) {
        ll u = fila.front();
        fila.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) fila.push_front(v);
                else fila.push_back(v);
            }
        }
    }

    long long r = min(dist[n], dist[2 * n]);
    return r == INF ? -1 : r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> lista(n + 1);
    for (ll i = 1; i <= m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        lista[a].push_back({b, c});
    }
    cout << menorCaminho(lista) << "\n";
}