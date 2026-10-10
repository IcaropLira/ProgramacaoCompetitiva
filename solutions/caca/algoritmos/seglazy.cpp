#include <bits/stdc++.h>
#include <ratio>
#define endl "\n"
using namespace std;

using ll = long long;

int n;
vector<int> nums;
vector<ll> lazy;

struct sgtl{
    vector<ll> segtlazy;
    void init(){
        segtlazy.resize(4 * (n+1));
        build(1,n,1);
    }
    
    void build(int l, int r, int node) {
        if(l == r) {
            segtlazy[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2);
        build(mid + 1, r, node * 2 + 1);
        segtlazy[node] = segtlazy[node * 2] + segtlazy[node * 2 + 1];
    }

    void push(int l, int r, int node) {
        if(lazy[node] != 0) {
            segtlazy[node] += lazy[node] * (r - l + 1);
        }
        if(l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(int l, int r, int ql, int qr, int val, int node) {
        push(l, r, node);
        if(l > qr || r < ql) return;
        if(l >= ql && r <= qr){
            lazy[node] += val;
            push(l, r, node);
            return;
        }
        
        int mid = (l + r) / 2;
        update(l, mid, ql, qr, val, node * 2);
        update(mid + 1, r, ql, qr, val, node * 2 + 1);
        segtlazy[node] = segtlazy[node * 2] + segtlazy[2 * node + 1];
    }

    ll query(int l, int r, int ql, int qr, int node) {
        push(l,r, node);
        if(l > qr || r < ql) return 0;
        if(l >= ql && r <= qr) {
            return segtlazy[node];
        }
        
        int mid = (l + r) / 2;
        return query(l, mid, ql, qr, node * 2) + query(mid + 1, r, ql, qr, node * 2 + 1);
    }
};

void solve() {
    
    sgtl seg;
    int q; cin >> n >> q;
    nums.resize(n + 1);
    lazy.resize(4 * (n + 1));

    for(int i = 1; i <= n; i++) cin >> nums[i];
    seg.init();

    while(q--) {
        int type; cin >> type;
        if(type == 2) {

            int k; cin >> k;
            cout << seg.query(1, n, k, k, 1) << endl;
        }
        else {
            int a, b, u; cin >> a >> b >> u;
            seg.update(1, n, a, b, u, 1);
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

