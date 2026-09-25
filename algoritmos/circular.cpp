#include <bits/stdc++.h>
#include <sstream>
#define all(v) v.begin(), v.end()
#define endl "\n"
using namespace std;
using ll = long long;

int n;
vector<ll> nums;
vector<ll> lazy;

struct seglazy {
    vector<ll> seg;

    void init() {
        seg.resize(4 * n, 1e9);
        lazy.resize(4 * n);
        build(0, n-1, 0);
    }

    void build(int l, int r, int node) {
        if(l == r) {
            seg[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2 + 1);
        build(mid + 1, r, node * 2 + 2);
        seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
    }

    void push(int l, int r, int node) {
        if(lazy[node] == 0) return;

        seg[node] += lazy[node];
        if(l != r) {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(int l, int r, int lq, int rq, int node, int val) {
        push(l, r, node);
        if(l > rq || r < lq) return;
        if(l >= lq && r <= rq){
            lazy[node] += val;
            push(l, r, node);
            return;
        }

        int mid = (l + r) / 2;
        update(l, mid, lq, rq, node * 2 + 1, val);
        update(mid + 1, r, lq, rq, node * 2 + 2, val);
        seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
    }

    ll query(int l, int r, int lq, int rq, int node) {
        push(l, r, node);
        if(l > rq || r < lq) return 1e9;
        if(l >= lq && r <= rq) return seg[node];

        int mid = (l + r) / 2;
        return min(query(l, mid, lq, rq, node * 2 + 1), query(mid + 1, r, lq, rq, node * 2 + 2));
    }
};

void solve() {
    cin >> n;
    seglazy a;
    nums.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    a.init();

    int m; cin >> m;
    cin.ignore();

    while(m--) {
        string line;
        getline(cin, line);
        stringstream line2(line);

        vector<ll> linvec;
        ll x;
        while(line2 >> x) linvec.push_back(x);
            ll l, r, val;
            l = linvec[0];
            r = linvec[1];
        if(linvec.size() == 3) {
            val = linvec[2];
            if(l > r) {
                a.update(0, n - 1, l, n-1, 0, val);
                a.update(0, n - 1, 0, r, 0, val);
            }

            else a.update(0,n - 1,l,r,0,val);
        }
        else {
            if(l > r) {
                cout << min(a.query(0, n-1, l, n-1, 0), a.query(0, n - 1, 0, r, 0)) << endl;
            }
            else cout << a.query(0,n-1,l,r,0) << endl;
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

