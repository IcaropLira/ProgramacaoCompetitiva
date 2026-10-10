#include <bits/stdc++.h>
#define endl "\n";
using namespace std;
using ll = long long;

int n;
vector<int> nums;
struct seg{
    vector<ll> sg;

    void init() {
        sg.resize(4 * (n + 1));
        build(1, n, 1);

   }

    void build(int l, int r, int node) {
        if(l == r) {
            sg[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2 * node);
        build(mid + 1, r, node * 2 + 1);

        sg[node] = sg[node * 2] + sg[node * 2 + 1];
    }

    void update(int l, int r, int idx, int val, int node){
        if(l == r) {
            sg[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid) update(l, mid, idx, val, node * 2);
        else update(mid + 1, r, idx, val, node * 2 + 1);
        sg[node] = sg[node * 2] + sg[node * 2 + 1];
    }

    ll query(int l, int r, int ql, int qr, int node){
        if(l > qr || r < ql) return 0;
        if(l >= ql && r <= qr) return sg[node];

        int mid = (l + r) / 2;
        return query(l, mid, ql, qr, node * 2) + query(mid + 1, r, ql, qr, node * 2 + 1);
    }
};

void solve() {
    seg segtree;
    int q; cin >> n >> q;
    nums.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> nums[i];
    segtree.init();

    while(q--){
        int type, a,b; cin >> type >> a >> b;

        if(type == 1){
            segtree.update(1, n, a, b, 1);    
        }
        else {
            cout << segtree.query(1, n, a, b, 1) << endl;
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

