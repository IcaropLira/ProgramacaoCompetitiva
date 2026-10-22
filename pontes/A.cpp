#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj, arv;
unordered_set<int> vis;
vector<int> tin, low;
vector<pair<int, int>> roads;
int timer = 0;

void dfs(int no, int pai) {
    timer += 1;
    tin[no] = timer;
    low[no] = timer;
    vis.insert(no);
    for (int ch: adj[no]) {
        if (ch == pai) continue;
        if (vis.find(ch) != vis.end()) low[no] = min(low[no], tin[ch]);
        else {
            arv[no].push_back(ch);
            dfs(ch, no);
            low[no] = min(low[no], low[ch]);
        }
    }
}

void dfs_v(int no, int pai) {
    for (int ch: arv[no]) {
        if (ch == pai) continue;
        if (tin[no] < low[ch]) {
            roads.push_back({no, ch});
        }
        dfs_v(ch, no);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    arv.resize(n + 1);
    tin.resize(n + 1);
    low.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 1);
    dfs_v(1, 1);

    cout << roads.size() << endl;

    for (pair<int, int> r: roads) {
        cout << r.first << " " << r.second << endl;
    }
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

