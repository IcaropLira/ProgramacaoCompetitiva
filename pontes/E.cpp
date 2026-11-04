#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<int> in, low;
int timer = 0;
vector<pair<int, int>> ans;

void dfs(int v, int pr) {
    timer += 1;
    in[v] = timer;
    low[v] = timer;
    for (int ch: adj[v]) {
        if (ch == pr) continue;
        if (in[ch]) low[v] = min(low[v], in[ch]);
        else {
            dfs(ch, v);
            low[v] = min(low[v], low[ch]);
            if (in[v] < low[ch]) {
                cout << 0 << endl;
                exit(0);
            }
        }
    }
}

vector<int> vis;
int c = 0;
int m;
void dfs1(int v, int pr) {
    vis[v] = 1;
    for (int ch: adj[v]) {
        if (ch == pr) continue;
        if (c >= m) continue;
        c += 1;
        cout << v << " " << ch << endl;
        if (!vis[ch]) dfs1(ch, v);
    }
}

void solve() {
    int n; cin >> n >> m;

    adj.resize(n + 1);
    in.resize(n + 1);
    low.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);

    cout << '\n';

    dfs1(1, -1);
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

