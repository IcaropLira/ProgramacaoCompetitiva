#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> nums;

struct segt {
    vector<ll> seg;

    void init() {
        seg.resize(4 * (n + 1));
        build(1, n, 1);
    }

    void build(int l, int r, int node) {
        if(l == r) {
            seg[node] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, node * 2);
        build(mid + 1, r, node * 2 + 1);
        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    int query(int l, int r, int lq, int rq, int node) {
        if(l > rq || r < lq) return 0;
        if(l >= lq && r <= rq) return seg[node];

        int mid = (l + r) / 2;
        return max(query(l, mid, lq, rq, node * 2), query(mid + 1, r, lq, rq, node * 2 + 1));
    }
};

void solve() {
    int q; cin >> n >> q;
    nums.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> nums[i];
    segt seg;
    seg.init();

    while(q--) {
        int a, b; cin >> a >> b;
        int que = seg.query(1, n, a, b, 1);
        if(que == nums[a] || que == nums[b]) {
            cout << "Adilson" << endl;
        }
        else {
            if((b - a + 1) % 2) cout << "Reginaldo" << endl;
            else cout << "Adilson" << endl;
        }
    }
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

