#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    int total_invited = 0;

    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            int count0 = 0, count1 = 0;
            vector<int> q;
            
            color[i] = 0;
            count0++;
            q.push_back(i);

            int head = 0;
            while (head < (int)q.size()) {
                int u = q[head++];
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        if (color[v] == 0) count0++;
                        else count1++;
                        q.push_back(v);
                    }
                }
            }
            total_invited += max(count0, count1);
        }
    }

    cout << total_invited << "\n";
    return 0;
}