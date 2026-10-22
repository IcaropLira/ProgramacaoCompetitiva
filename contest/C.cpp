#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll inf = 1e9;

struct SEG {
    vector<ll> seg;

    SEG(int n): seg(4*n) {}

    void update(int l, int r, int node, int pos, ll val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int meio = (l + r) / 2;
        if (pos <= meio) update(l, meio, node * 2, pos, val);
        else update(meio + 1, r, node * 2 + 1, pos, val);
        seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
    }

    ll query(int l, int r, int node, int s, int e) {
        if (r < s || l > e) {
            return inf;
        }
        if (l >= s && r <= e) {
            return seg[node];
        }
        int meio = (l + r) / 2;
        return min(query(l, meio, node * 2, s, e), query(meio + 1, r, node * 2 + 1, s, e));
    }
};
void solve() {
    int n, m, k, d; cin >> n >> m >> k >> d;
    vector<int> pontes(n);
    for (int i = 0; i < n; i++) {
        SEG seg(m);
        seg.update(1, m, 1, 1, 1);
        int x; cin >> x;
        for (int j = 2; j <= m; j++) {
            cin >> x;
            int s = j - d - 1;
            if (s < 1) s = 1;
            ll val = seg.query(1, m, 1, s, j - 1) + x + 1;
            seg.update(1, m, 1, j, val);
        }
        pontes[i] = seg.query(1, m, 1, m, m);
    }
    sort(pontes.begin(), pontes.end());
    ll res = 0;
    for (int i = 0; i < k; i++){
        res += pontes[i];
    }  
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

