#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

using ll = long long;

struct bitt {
    vector<ll> b;
    
    bitt(int n) : b(n + 1) {}

    void add(int i, ll v) {
        for(; i < (int) b.size(); i += i & (-i)) b[i] = max(v, b[i]);
    }

    ll query(int i) {
        ll ans = 0;

        for(; i > 0; i -= i & (-i)) ans = max(b[i], ans);

        return ans;
    }

    ll query(int a, int b) {
        return query(b) - query(a - 1);
    }
};

struct segt {
    vector<ll> seg;

    segt(int n): seg(4 * n) {}

    void update(int node, int l, int r, int idx, ll v) {
        if(l == r) {
            seg[node] = max(v, seg[node]);
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid) update(node * 2, l, mid, idx, v);
        else update(node * 2 + 1, mid + 1, r, idx, v);

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

    vector<ll> nums(n);

    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<ll> sortn = nums;

    sort(all(sortn));
    sortn.erase(unique(all(sortn)), sortn.end());


    for(int i = 0; i < n; i++) {
        int it = lower_bound(all(sortn), nums[i]) - sortn.begin() + 1;
        nums[i] = it;
    }


    bitt b(n);

    segt s(n + 1);

    for(int i = 0; i < n; i++) {
        ll melhor = b.query(nums[i] - 1);

        b.add(nums[i], melhor + 1);
    }

    for(int i = 0; i < n; i++) {
        ll melhor = s.query(1, 1, n, 1, nums[i] - 1);

        s.update(1, 1, n, nums[i], melhor + 1);
    }

    cout << s.query(1,1,n,1,n) << '\n';

    //cout << b.query(n) << '\n';
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
