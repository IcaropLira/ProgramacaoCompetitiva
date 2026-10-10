#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

struct lazySeg {
    vector<ll> seg;
    vector<ll> lazy;

    void init(int n, vector<ll> &arr){
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
        build(1, n, 1, arr);
    }

    void build(int l, int r, int node, vector<ll> &arr){
        if (l == r){
            seg[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2, arr);
        build(mid + 1, r, node * 2 + 1, arr);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    void update(int l, int r, int node, ll val, int s, int e){
        push(l, r, node);
        if (s > r || e < l) {
            return;
        }

        if (l >= s && r <= e) {
            lazy[node] += val;
            push(l, r, node);
            return;
        }

        int mid = (r + l) / 2;
        update(l, mid, node * 2, val, s, e);
        update(mid + 1, r, node * 2 + 1, val, s, e);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    void push(int l, int r, int node){
        seg[node] += lazy[node] * (r - l  + 1);
        if (l != r){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node]; 
        }
        lazy[node] = 0;
    }

    ll query(int l, int r, int node, int s, int e){
        push(l, r, node);

        if (s > r || e < l) {
            return 0;
        }
        

        if (l >= s && r <= e) {
            return seg[node];
        }

        int mid = (r + l) / 2;
        return query(l, mid, node * 2, s, e) +
            query(mid + 1, r, node * 2 + 1, s, e);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    lazySeg seg;
    vector<ll> arr(n+1);

    seg.init(n, arr);

    while (m--) {
        int x; cin >> x;
        if (x) {
            int y, z; cin >> y >> z;
            cout << seg.query(1, n, 1, y, z) << endl;
            continue;
        }
        ll k;
        int y, z; cin >> y >> z >> k;
        seg.update(1, n, 1, k, y, z);
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
