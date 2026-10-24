#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<int> tin, low;
vector<pair<int, int>> roads;
int timer = 0;

void dfs(int no, int pai) {
    timer += 1;
    tin[no] = timer;
    low[no] = timer;
    for (int ch: adj[no]) {
        if (ch == pai) continue;
        if (tin[ch]) low[no] = min(low[no], tin[ch]);
        else {
            dfs(ch, no);
            low[no] = min(low[no], low[ch]);
            if (tin[no] < low[ch]) {
                roads.push_back({min(no, ch), max(ch, no)});
            }
        }
    }
}

int caso = 0;

void solve() {
    int n, m; cin >> n >> m;
    adj.assign(n + 1, {});
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    roads.clear();
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 1);

    caso += 1;
    cout << "Caso #" << caso << endl;
    if (!roads.size()) {
        cout << "Sin bloqueos" << endl;
        return;
    }
    cout << roads.size() << endl;

    sort(roads.begin(), roads.end());
    for (pair<int, int> r: roads) {
        cout << r.first << " " << r.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

