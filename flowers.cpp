#include <bits/stdc++.h>
using namespace std;
using ll = long long;



struct segt {
    vector<ll> seg;

    segt(int n) : seg(4 * (n)) {}

    void build(int l, int r, int node, vector<int> &nums) {
        if(l == r) {
            seg[node] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, node * 2, nums);
        build(mid + 1, r, node * 2 + 1, nums);

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int l, int r, int node, ll val, int idx) {
        if(l == r) {
            seg[node] = max(val, seg[node]);
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid) update(l, mid, node * 2, val, idx);
        else update(mid + 1, r, node * 2 + 1, val, idx);

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    ll query(int node, int l, int r, int lq, int rq) {
        if(l > rq || r < lq) return 0;

        if(l >= lq && r <= rq) return seg[node];

        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, lq, rq), query(node * 2 + 1, mid + 1, r, lq, rq));
    }
};

void solve() {
    int n; cin >> n;

    vector<int> h(n);
    vector<ll> b(n);

    segt s(n);

    for(int i = 0; i < n; i++) cin >> h[i];

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        ll melhor = s.query(1, 1, n, 1, h[i] - 1);

        s.update(1, n, 1, b[i] + melhor, h[i]);
    }

    cout << s.query(1, 1, n, 1, n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}
