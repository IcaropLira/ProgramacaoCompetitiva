#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
ll seg[4 * N];

ll query(int no, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return seg[no];

    int meio = (l + r) / 2;

    return max(query(no * 2, l, meio, ql, qr), query(no * 2 + 1, meio + 1, r, ql, qr));
}

void update(int no, int l, int r, int pos, ll valor) {
    if (l == r) {
        seg[no] = max(seg[no], valor);
        return;
    }

    int meio = (l + r) / 2;

    if (pos <= meio) update(no * 2, l, meio, pos, valor);
    else update(no * 2 + 1, meio + 1, r, pos, valor);

    seg[no] = max(seg[no * 2], seg[no * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n);
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        ll best = query(1, 1, n, 1, h[i] - 1);
        ll cur = best + a[i];

        update(1, 1, n, h[i], cur);
    }

    cout << query(1, 1, n, 1, n) << '\n';

    return 0;
}
