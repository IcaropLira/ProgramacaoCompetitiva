#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define all(l) l.begin(), l.end()

vector<vector<int>> adj;
vector<int> in, out;

struct BIT
{
    vector<ll> bit;
    int n;

    BIT(int n): n(n), bit(n+1) {}

    void update(int i, ll val) {
        while(i <= n) {
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

int timer = 0;

void dfs(int no, int pai) {
    timer += 1;
    in[no] = timer;
    for (int ch: adj[no]) {
        if (ch == pai) continue;
        dfs(ch, no);
    }
    timer += 1;
    out[no] = timer;
}


int main() {
    int n, q; cin >> n >> q;

    adj.resize(n + 1);
    in.resize(2 * n + 1);
    out.resize(2 * n + 1);
    BIT bit(2 * n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);

    while (q--) {
        int x, y; cin >> x >> y;
        bit.update(in[x], y);
        bit.update(out[x] + 1, -y);
    }

    for (int i = 1; i <= n; i++) {
        cout << bit.query(out[i]) << ' ';
    }
    cout << endl;

    return 0;
}