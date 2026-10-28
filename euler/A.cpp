#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> in;
vector<int> out;
vector<ll> euler;
vector<vector<int>> adj;
vector<ll> nos;

struct BIT{
    
    vector<ll> bit;
    int n;

    BIT(int n): bit(n), n(n) {}

    void update(int i, ll val){
        while(i < n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    ll query(int i) {
        ll res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};

int dfs(int no, int pai, int idx) {
    idx += 1;
    in[no] = idx;
    for (int ch: adj[no]) {
        if (ch == pai) continue;
        idx = dfs(ch, no, idx);
    }
    out[no] = idx;
    return idx;
}

void solve() {
    int n, q; cin >> n >> q;

    nos.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nos[i];
    }

    adj.resize(n + 1);
    for (int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    in.resize(n + 1);
    out.resize(n + 1);
    dfs(1, 1, 0);

    BIT bit(n + 1);
    for (int i = 1; i <= n; i++) bit.update(in[i], nos[i]);

    while (q--) {
        int x;
        cin >> x;
        if (x == 2) { 
            int y;
            cin >> y;
            cout << bit.query(out[y]) - bit.query(in[y] - 1) << endl;
        } else {
            int y, p; cin >> y >> p;
            bit.update(in[y], p - nos[y]);
            nos[y] = p;
        }
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

