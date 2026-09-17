#include "testlib.h"
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>(1);
    int m = opt<int>(2);
    string type = opt<string>(3, "random");
    vector<pair<int, int>> edges;
    set<pair<int, int>> edge_set;

    if (type == "tree") {
        m = n - 1;
        vector<int> color(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            int p = rnd.next(1, i - 1);
            edges.push_back({p, i});
        }
    } else {
        vector<int> partA, partB;
        
        if (type == "unbalanced") {
            int szA = max(1, n / 10);
            for (int i = 1; i <= n; ++i) {
                if (i <= szA) partA.push_back(i);
                else partB.push_back(i);
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                if (rnd.next(2) == 0) partA.push_back(i);
                else partB.push_back(i);
            }
        }

        if (partA.empty()) { partA.push_back(1); partB.erase(partB.begin()); }
        if (partB.empty()) { partB.push_back(n); partA.pop_back(); }

        long long max_possible_edges = 1LL * partA.size() * partB.size();
        m = min((long long)m, max_possible_edges);

        while ((int)edges.size() < m) {
            int u = partA[rnd.next((int)partA.size())];
            int v = partB[rnd.next((int)partB.size())];

            if (u > v) swap(u, v);

            if (edge_set.find({u, v}) == edge_set.end()) {
                edge_set.insert({u, v});
                edges.push_back({u, v});
            }
        }
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) p[i] = i;
    shuffle(p.begin() + 1, p.end());

    vector<pair<int, int>> final_edges;
    for (auto& edge : edges) {
        int u = p[edge.first];
        int v = p[edge.second];
        if (rnd.next(2) == 1) swap(u, v);
        final_edges.push_back({u, v});
    }

    shuffle(final_edges.begin(), final_edges.end());

    cout << n << " " << final_edges.size() << "\n";
    for (auto& edge : final_edges) {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}