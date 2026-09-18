#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int n;
vector<int> nums;
vector<ll> lazy;

struct sg{
    vector<ll> seg;

    void init(){
        seg.resize(4 * (n + 1));
        lazy.resize(4 * (n + 1));
        build(1, n, 1);
    }

    void build(int l, int r, int node) {
        push(l,r,node);
        if(l == r) {
            seg[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2);
        build(mid + 1, r, node * 2 + 1);
        seg[node] = seg[node * 2] +  seg[node * 2 + 1];
    }

    void push(int l, int r, int node) {
        if(lazy[node] != 0) {
            seg[node] += lazy[node] * (r - l + 1);
        }
        if(l != r) {
           lazy[node * 2] += lazy[node];
           lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }


    void update(int l, int r, int ql, int qr, int val, int node) {
        push(l,r,node);
        if(l > qr || r < ql) return;
        if(l >= ql && r <= qr) {
            lazy[node] += val;
            push(l,r,node);
            return;
        }

        int mid = (l + r) / 2;
        update(l, mid, ql, qr, val, node * 2);
        update(mid + 1, r, ql, qr, val, node * 2 + 1);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }    

    ll query(int l, int r, int ql, int qr, int node) {
        push(l,r,node);
        if(l > qr || r <  ql) return 0;
        if(l >= ql && r <= qr) return seg[node];

        int mid = (l + r) / 2;
        return query(l, mid, ql, qr, node * 2) + query(mid + 1, r, ql, qr, node * 2 + 1);
    }
};

void solve() {
    sg s;
    int q; cin >> n >> q;
    nums.resize(n + 1);

    s.init();
    while(q--) {
        int type; cin >> type;
        if(type == 0) {
            int p, q, v; cin >> p >> q >> v;
            s.update(1,n,p,q,v, 1);
        }
        else {
            int p, q; cin >> p >> q;
            cout << s.query(1, n, p, q, 1) << endl;
        }
    }
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

