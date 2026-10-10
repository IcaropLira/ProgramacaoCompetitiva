#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int n;
vector<ll> lazy;
vector<int> nums;
vector<pair<ll, int>> indices;

struct seglazy {
    vector<ll> seg;

    void init() {
        seg.resize(4 * (n + 1));
        lazy.resize(4 * (n + 1));
    }

    void build(int l, int r, int node, vector<ll>& nums) {
        if(l == r) {
            seg[node] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, node * 2, nums);
        build(mid + 1, r, node * 2 + 1, nums);
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
        push(l, r, node);
        if(l > rq || r < lq) return;
        if(l >= lq && r <= rq) {
            lazy[node] += val;
            push(l, r, node);
            return;
        }

        int mid = (l + r) / 2;
        update(l, mid, lq, rq, val, node * 2);
        update(mid + 1, r, lq, rq, val, node * 2 + 1);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }


    ll query(int l, int r, int lq, int rq, int node) {
        //push(l,r,node);
        if(l > rq || r < lq) return 0;
        if(l >= lq && r <= rq) return seg[node];

        int mid = (l + r) / 2;
        return query(l, mid, lq, rq, node * 2) + query(mid + 1, r, lq, rq, node * 2 + 1);
    }

    void tacanalista(int l, int r, int node) {
        push(l,r,node);
        if(l == r) {
            indices[l].first = seg[node];
            return;
        }

        int mid = (l + r) / 2;
        tacanalista(l, mid, node * 2);
        tacanalista(mid + 1, r, node * 2 + 1);
    }
};

void solve() {
    seglazy freq;
    int q; cin >> n >> q;
    indices.resize(n + 1);
    for(int i = 1; i <= n; i++) indices[i].second = i;

    freq.init();

    nums.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> nums[i];

    vector<pair<int,int>> queries;
     while(q--) {
        int l, r; cin >> l >> r;
        queries.push_back({l, r});
        freq.update(1,n,l,r,1,1);
    }

    freq.tacanalista(1,n, 1);

    sort(all(nums)); 
    reverse(all(nums));
    sort(all(indices));
    reverse(all(indices));

    vector<ll> numspraseg(n+1);

    int i = 0;
    for(auto [a,b] : indices) {
        numspraseg[b] = nums[i];
        i++;
    }

    seglazy seg;
    seg.init();
    seg.build(1, n, 1, numspraseg);

    ll resp = 0;

    for(auto [a,b] : queries) {
        resp += seg.query(1, n, a, b, 1);
    }

    cout << resp << endl;

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

