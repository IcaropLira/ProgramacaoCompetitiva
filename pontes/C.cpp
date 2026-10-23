#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> tin, low;
vector<pair<int, int>> roads;
int timer = 0;
vector<int> vis;

void dfs(int no, int pai) {
    if (vis[no]) return;
    vis[no] = 1;
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

void solve() {
    int n;
    
    while (cin >> n) {
        adj.assign(n, {});
        tin.assign(n, 0);
        low.assign(n, 0);
        roads.clear();
        vis.assign(n, 0);
        
        for (int i = 0; i < n; ++i) {
            int u, m;
            
            scanf("%d (%d)", &u, &m);
            
            for (int j = 0; j < m; ++j) {
                int v;
                cin >> v;
                adj[u].push_back(v);
            }
        }
        
        // A lista de adjacências 'adj' está montada para o caso atual.
        for (int i = 0; i < adj.size(); i++) {
            dfs(i, -1);
        }

        cout << roads.size() << " critical links" << endl;
        sort(roads.begin(), roads.end());

        for (pair<int, int> r: roads) {
            cout << r.first << " - " << r.second << endl;
        }

        cout << endl;
    }
}

int main(){
    solve();

}

