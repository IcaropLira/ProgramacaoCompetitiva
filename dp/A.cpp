#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SEG{
    
    vector<ll> seg;

    SEG(int n): seg(n*4) {}
    
    void update(int l, int r, int node, int pos, ll val){
        if (l == r){
            seg[node] = val;
            return;
        }
        int meio = (l + r) / 2;
        if (pos <= meio) update(l, meio, node * 2, pos, val);
        else update(meio + 1, r, node * 2 + 1, pos, val);
        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    ll query(int l, int r, int node, int s, int e) {
        if (r < s || l > e) {
            return 0;
        }
        if (l >= s && r <= e){
            return seg[node];
        }
        int meio = (l + r) / 2;
        return max(query(l, meio, node * 2, s, e), query(meio + 1, r, node * 2 + 1, s, e)); 
    }

};

void solve() {
    int n; cin >> n;

    vector<ll> h(n);
    vector<ll> b(n);

    SEG seg(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    for (int i = 0; i < n; i++){
        seg.update(1, n, 1, h[i], b[i] + seg.query(1, n, 1, 1, h[i]));
    }

    cout << seg.query(1, n, 1, 1, n) << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

