#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<ll> in(n + 1), dist(n + 1, 1e9), ant(n + 1, 0);
    queue<int> fila;

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        in[y] += 1;
    }

    fila.push(1);
    dist[1] = 0;

    while (!fila.empty()) {
        int top = fila.front();
        fila.pop();
        for (int ch: adj[top]) {
            ant[ch] = (ant[ch] + 1) % mod;
            fila.push(ch);
        }
    }
    cout << ant[n] % mod << endl;

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

