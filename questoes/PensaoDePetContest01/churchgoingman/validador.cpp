#include "testlib.h"
#include <vector>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 200000, "n");
    inf.readSpace();
    int m = inf.readInt(0, 200000, "m");
    inf.readEoln();

    vector<vector<int>> adj(n + 1);
    set<pair<int, int>> edges;

    for (int i = 0; i < m; ++i) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readEoln();

        ensuref(u != v, "Self-loop found on vertex %d", u);
        
        int a = min(u, v);
        int b = max(u, v);
        ensuref(edges.count({a, b}) == 0, "Multiple edges found between %d and %d", a, b);
        edges.insert({a, b});

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    inf.readEof();

    // Checa se o grafo é bipartido
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            vector<int> q;
            color[i] = 0;
            q.push_back(i);
            int head = 0;

            while (head < (int)q.size()) {
                int u = q[head++];
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push_back(v);
                    } else {
                        ensuref(color[v] != color[u], "Graph is not bipartite! Edge (%d, %d)", u, v);
                    }
                }
            }
        }
    }

    return 0;
}