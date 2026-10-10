#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using ll = long long;

int n;
vector<ll> nums;
vector<ll> lazynums;
struct lazy {
    vector<ll> seg;

    void init() {
        seg.resize(4 * (n + 1));
        lazynums.resize(4 * (n+1));
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
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    void push(int l, int r, int node) {
        if(lazynums[node] == 0) return;
        seg[node] += (r - l + 1) * lazynums[node];
        
        if(l != r) {
            lazynums[node * 2] += lazynums[node];
            lazynums[node * 2 + 1] += lazynums[node];
        }
        lazynums[node] = 0;
    }

    void update(int l, int r, int lq, int rq, int node, int valor) {
        push(l,r,node);
        if(l > rq || r < lq) return;
        if(l >= lq && r <= rq) {
            lazynums[node] += valor;
            push(l, r, node);
            return;
        }

        int mid = (l + r) / 2;
        update(l, mid, lq, rq, node * 2, valor);
        update(mid + 1, r, lq, rq, node * 2 + 1, valor);
        seg[node] = seg[node * 2 + 1] + seg[node * 2];
    }

    ll query(int l, int r, int lq, int rq, int node) {
        push(l,r,node);
        if(l > rq || r < lq) return 0;
        if(l >= lq && r <= rq) {
            return seg[node];
        }

        int mid = (l + r) / 2;
        return query(l, mid, lq, rq, node * 2) + query(mid + 1, r, lq, rq, node * 2 + 1);
    }

};

lazy a;

void solve() {
   int type; cin >> type;
   if(type == 1) {
       int k, p; cin >> k >> p; 
           cout << a.query(1,n,k,p,1) << "\n";
   }
   else {
        int u, v, w; cin >> u >> v >> w;
        a.update(1, n, u, v,1,  w);
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sla; cin >> sla;
    while(sla--){
    int t; cin >> n >> t;
    nums.resize(n + 1);

    //for(int i = 1; i <= n; i++) cin >> nums[i];
    a.init(); 

    while (t--) {
        solve();
    }
    }
    return 0;
}

