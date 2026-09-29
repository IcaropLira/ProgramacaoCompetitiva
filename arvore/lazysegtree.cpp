#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;

// lazy seg tree de soma
vector<ll> seg, lazy, p;

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

void propagate(int no, int l, int r) {
    if (lazy[no] == 0) return;

    seg[no] += lazy[no] * (r - l + 1); // atualiza o no correspondente ao intervalo (r - l + 1)

    if (l != r) {
        lazy[no * 2] += lazy[no];
        lazy[no * 2 + 1] += lazy[no];
    }

    lazy[no] = 0;
}

void update(int no, int l, int r, int ql, int qr, ll val) {
    propagate(no, l, r);

    if (r < ql || l > qr) return;
    if (ql <= l && r <= qr) {
        lazy[no] += val;
        propagate(no, l, r);
        return;
    }

    int meio = (l + r) / 2;

    update(no * 2, l, meio, ql, qr, val);
    update(no * 2 + 1, meio + 1, r, ql, qr, val);

    seg[no] = seg[no * 2] + seg[no * 2 + 1];
}

ll query(int no, int l, int r, int ql, int qr) {
    propagate(no, l, r);

    if (r < ql || l > qr) return 0; // elemento neutro
    if (ql <= l && r <= qr) return seg[no];

    int meio = (l + r) / 2;

    return query(no * 2, l, meio, ql, qr) + query(no * 2 + 1, meio + 1, r, ql, qr);
}

void solve() {
    int n, q; cin >> n >> q;
    seg.resize(n * 4);
    lazy.resize(n * 4);
    p.resize(n + 1); // 1 indexado, morte ao 0 indexado
    for (int i = 1; i <= n; i++) cin >> p[i];

    build(1, 1, n);

    while(q--) {
        ll x; cin >> x;

        if (x == 1) {
            ll a, b, v; cin >> a >> b >> v;
            update(1, 1, n, a, b, v); // incrementa v no range [a, b]
        }
        else {
            ll a, b; cin >> a >> b;
            cout << query(1, 1, n, a, b) << '\n';
        }
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