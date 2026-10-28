#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define all(l) l.begin(), l.end()

vector<vector<int>> adj;
vector<int> in, out, nos;
int timer = 0;

struct SEG {
    vector<int> seg;
    vector<int> lazy;

    SEG(int n): seg(4 * n), lazy(4 * n) {}

    void update(int l, int r, int node, int s, int e) {
        push(node, l, r);
        if (l > e || r < s) {
            return;
        }
        if (l >= s && r <= e) {
            lazy[node] ^= 1;
            push(node, l, r);
            return;
        }
        int meio = (l + r) / 2;
        update(l, meio, node * 2, s, e);
        update(meio + 1, r, node * 2 + 1, s, e);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    void push(int node, int l, int r) {
        if (!lazy[node]) return;
        lazy[node] = 0;
        seg[node] += r - l + 1 - 2 * seg[node];
        if (l != r) {
            lazy[node * 2] ^= 1;
            lazy[node * 2 + 1] ^= 1;
        }
    }

    int query(int l, int r, int node, int s, int e) {
        push(node, l, r);
        if (l > e || r < s) {
            return 0;
        }
        if (l >= s && r <= e) {
            return seg[node];
        }
        int meio = (l + r) / 2;
        return query(l, meio, node * 2, s, e) + query(meio + 1, r, node * 2 + 1, s, e);
    }
};

void dfs(int no, int pr) {
    timer += 1;
    in[no] = timer;
    for (int ch: adj[no]) {
        if (ch == pr) continue;
        dfs(ch, no);
    }
    out[no] = timer;
}

int main() {
    int n; cin >> n;

    adj.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    nos.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        cin >> nos[i];
    }

    dfs(1, -1);

    SEG seg(n + 1);

    for (int i = 1; i <= n; i++) {
        if (nos[i]) seg.update(1, n, 1, in[i], in[i]);
    }

    int q; cin >> q;
    while (q--) {
        string s;
        int k; cin >> s >> k;
        if (s == "pow") {
            seg.update(1, n, 1, in[k], out[k]);
        } else {
            cout << seg.query(1, n, 1, in[k], out[k]) << endl;
        }
    }

    return 0;
}