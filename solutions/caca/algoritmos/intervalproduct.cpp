#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> nums;

struct segt {
    vector<ll> seg;

    void init() {
        seg.resize(4 * (n+1));
        build(1,n,1);
    } 

    void build(int l, int r, int node) {
        if(l == r) {
            seg[node] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, node * 2);
        build(mid + 1, r, node * 2 + 1);

        seg[node] = seg[node * 2] * seg[node * 2 + 1];
    }

    void update(int l, int r, int idx, int val, int node) {
        if(l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if(idx <= mid) update(l, mid, idx, val, 2 * node);
        else update(mid + 1, r, idx, val, node * 2 + 1);
        seg[node] = seg[node * 2] * seg[node * 2 + 1];
    }

    ll query(int l, int r, int lq, int rq, int node) {
        if(l > rq || r < lq) return 1;
        if(l >= lq && r <= rq) {
            return seg[node];
        }

        int mid = (l + r) / 2;
        return query(l, mid, lq, rq, node * 2) * query(mid + 1, r, lq, rq, node * 2 + 1);
    }
};

void solve() {
    int q;

    while( cin >> n >> q) {

    nums.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(x < 0) nums[i] = -1;
        else if(x > 0) nums[i] = 1;
        else nums[i] = 0;

    }

    segt seg;
    seg.init();
    
    string resp = "";
    while(q--) {
        string type; cin >> type;
        if(type == "C") {
            int a, b; cin >> a >> b;
            if(b > 0) b = 1;
            else if(b < 0) b = -1;
            else b = 0;
            seg.update(1,n,a,b,1);
        }

        else {
            int l, r; cin >> l >> r;
            int q = seg.query(1,n,l,r,1);
            if(q == 0) resp += "0";
            else if(q < 0) resp += "-";
            else resp += "+";
        }
    }
    cout << resp << endl;
    }
}

int main() {

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}

