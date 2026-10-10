#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

vector<vector<int>> p;
vector<int> dep;
const int LOG = 20;

void build(int no, vector<vector<int>>& adj, int pai) {
    for (int i = 1; i < LOG; i++) {
        p[no][i] = p[p[no][i - 1]][i - 1];
    }

    for (int ch : adj[no]) {
        if (ch == pai) continue;
        dep[ch] = dep[no] + 1;
        p[ch][0] = no;
        build(ch, adj, no);
    }
}

int lca(int x, int y, int c) {
    int a = x;
    int b = y;

    if (dep[a] < dep[b]) {
        swap(a, b);
    }

    int dist = dep[a] - dep[b];

    int pulos = 0;

    for (int i = 0; i < LOG; i++) {
        if (dist & (1 << i)) {
            a = p[a][i];
            pulos += (1 << i);
        }
    }

    if (a == b) {
        if (c >= pulos) {
            return y;
        }
        for (int i = 0; i < LOG; i++) {
            if (c & (1 << i)) {
                x = p[x][i];
            }
        }
        return x;
    } 

    for (int i = LOG - 1; i >= 0; i--) {
        if (p[a][i] != p[b][i]) {
            a = p[a][i];
            b = p[b][i];
            pulos += (1 << i);
        }
    }

    pulos += 2;

    if (c >= pulos) {
        return y;
    }

    if (c > pulos / 2 - dist) {
        swap(x, y);
        c = pulos - c;
    }

    for (int i = 0; i < LOG; i++) {
        if (c & (1 << i)) {
            x = p[x][i];
        }
    }

    return x;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    p.resize(n + 1, vector<int>(LOG));
    dep.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    build(1, adj, 1);

    int q;
    cin >> q;

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << lca(x, y, z) << endl;
    }

    return 0;
}