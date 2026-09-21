#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) static_cast<int>((x).size())

const int INF  = 1e9;
const ll LINF  = 1e18;
const int MOD  = 1e9 + 7;

struct segt{
    vector<ll> tree;
    vector<ll> lazy;

    void init(int n, vector<ll> &arr) {
        tree.resize(n*4);
        lazy.resize(n*4);
        build(1, n, 1, arr);
    }

    void build(int l, int r, int node, vector<ll> &arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node*2, arr);
        build(mid + 1, r, node*2+1, arr);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    void update(int l, int r, int node, int s, int e, int val){
        if (l >= s && r <= e){
            tree[node] += val * (r - l + 1);
            lazy[node * 2] = val;
            lazy[node * 2 + 1] = val;
            return;
        }
        if (r < s || l > e){
            return;
        }
        int mid = (l + r) / 2;
        update(l, mid, node * 2, s, e, val);
        update(mid + 1, r, node * 2 + 1, s, e, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    ll query(int l, int r, int node, int s, int e) {
        push(l, r, node);
        if (l >= s && r <= e){
            cout << l << r << endl;
            return tree[node];
        }
        if (r < s || l > e){
            return 0;
        }
        int mid = (l + r) / 2;
        query(l, mid, node * 2, s, e);
        query(mid + 1, r, node * 2 + 1, s, e);
        return tree[node * 2] + tree[node * 2 + 1];
    }

    void push(int l, int r, int node){
        tree[node] += lazy[node] * (r - l + 1);
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
        lazy[node] = 0;
    }
};

void solve(int tc) {
    int n, q; cin >> n >> q;
    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    segt arv;
    arv.init(n, arr);

    for (int i = 0; i < q; i++){
        int x; cin >> x;
        int y, z, u;
        if (x == 1){
            cin >> y >> z >> u;
            arv.update(1, n, 1, y, z, u);
        } else {
            cin >> y;
            cout << arv.query(1, n, 1, y, y) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    
    for (int tc = 1; tc <= t; ++tc) {
        solve(tc);
    }

    return 0;
}