#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define all(l) l.begin(), l.end()

vector<ll> nos, in, out;
vector<vector<int>> adj;
int timer = 0;

struct BIT{

    vector<ll> bit;
    int n;

    BIT(int n): n(n), bit(n + 1) {}

    void update(int no, ll val) {
        while (no <= n) {
            bit[no] += val;
            no += no & -no;
        }
    }

    ll query(int no) {
        ll res = 0;
        while (no > 0) {
            res += bit[no];
            no -= no & -no;
        }
        return res;
    }
};

void dfs(int no, int pai) {
    timer += 1;
    in[no] = timer;
    for (int ch: adj[no]) {
        if (ch == pai) continue;
        dfs(ch, no);
    }
    out[no] = timer;
}

int main() {
    int n, q; cin >> n >> q;

    nos.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> nos[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);

    BIT bit(n + 1);
    for (int i = 1; i <= n; i++) {
        bit.update(in[i], nos[i]);
        bit.update(out[i] + 1, -nos[i]);
    }

    while (q--) {
        int x, y, z;
        cin >> x >> y;
        if (x == 1) {
            cin >> z;
            int val = z - nos[y];
            nos[y] = z;
            bit.update(in[y], val);
            bit.update(out[y]  + 1, -val);
        } else {
            cout << bit.query(in[y]) << endl;
        }
    }
    return 0;
}