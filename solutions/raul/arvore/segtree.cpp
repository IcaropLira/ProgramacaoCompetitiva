#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;

// usando como referencia a questao Dynamic Range Sum Queries do cses
vector<ll> seg, p;

void build(int no, int l, int r) {
    if (l == r) {
        seg[no] = p[l];
        return;
    }

    int meio = (l + r) / 2;

    build(no * 2, l, meio);
    build(no * 2 + 1, meio + 1, r);

    seg[no] = seg[no * 2] + seg[no * 2 + 1];
}

void update(int no, int l, int r, int idx, ll val) {
    if (l == r) {
        seg[no] = val;
        return;
    }

    int meio = (l + r) / 2;

    if (idx <= meio) update(no * 2, l, meio, idx, val);
    else update(no * 2 + 1, meio + 1, r, idx, val);

    seg[no] = seg[no * 2] + seg[no * 2 + 1];
}

ll query(int no, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0; // elemento neutro
    if (ql <= l && r <= qr) return seg[no];

    int meio = (l + r) / 2;

    return query(no * 2, l, meio, ql, qr) + query(no * 2 + 1, meio + 1, r, ql, qr);
}

void solve() {
    int n, q; cin >> n >> q;
    seg.resize(n * 4);
    p.resize(n + 1); // 1 indexado, morte ao 0 indexado
    for (int i = 1; i <= n; i++) cin >> p[i];

    build(1, 1, n);

    while(q--) {
        ll x, a, b; cin >> x >> a >> b;

        if (x == 1) update(1, 1, n, a, b);
        else cout << query(1, 1, n, a, b) << '\n';
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t = 1;
    //cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}