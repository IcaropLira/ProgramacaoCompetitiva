#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define endl "\n"
#define ll long long

using namespace std;

vector<ll> lazy;
struct lazys {
    vector<ll> seg;

    void init(int n) {
        seg.resize(4 * (n + 1));
        lazy.resize(4 * (n + 1));
    }

    void build(int r, vector<int> &nums, int l = 1, int node = 1) {
        if(l == r) {
            seg[node] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        build(r, nums, mid + 1, node * 2 + 1);
        build(mid, nums, l, node * 2);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    void push(int l, int r, int node) {
        if(lazy[node] == 0) return;

        seg[node] += (r - l + 1) * lazy[node];

        if(l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    void update(int l, int r, int lq, int rq, int val, int node) {
        push(l,r,node);
        if(l > rq || r < lq) return;
        if(l >= lq && r <= rq) {
            lazy[node] += val;
            push(l,r, node);
            return;
        }

        int mid = (l + r) / 2;
        update(l, mid, lq, rq, val, node * 2);
        update(mid + 1, r, lq, rq, val, node * 2 + 1);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    ll query(int l, int r, int lq, int rq, int node) {
        push(l,r,node);
        if(l > rq || r < lq) return 0;
        if(l >= lq && r <= rq) return seg[node];

        int mid = (l + r) / 2;

       return query(l, mid, lq, rq, node * 2) + query(mid + 1, r, lq, rq, node * 2 + 1);
    }
};



void solve() {
    int n, q; cin >> n >> q;
    vector<int> nums(n + 1);

    for(int i = 1; i <= n; i++) cin >> nums[i];

    lazys b;
    b.init(n);
    b.build(n, nums);

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int l, r, k; cin >> l >> r >> k;
            b.update(1, n, l, r, k, 1);
        }
        else {
            int a; cin >> a;
            cout << b.query(1,n,a,a,1) << endl;
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

