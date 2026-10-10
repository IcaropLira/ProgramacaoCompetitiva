#include <bits/stdc++.h>
using namespace std;

void build(int no, int l, int r, vector<int>& seg, const vector<int>& p) {
    if (l == r) {
        if (p[l] > 0) seg[no] = 1;
        else if (p[l] < 0) seg[no] = -1;
        else seg[no] = 0;
        return;
    }
    int meio = (l + r) / 2;
    build(2 * no, l, meio, seg, p);
    build(2 * no + 1, meio + 1, r, seg, p);
    seg[no] = seg[2 * no] * seg[2 * no + 1];
}

int query(int no, int l, int r, int ql, int qr, const vector<int>& seg) {
    if (r < ql || l > qr) return 1;
    if (ql <= l && qr >= r) return seg[no];
    int meio = (l + r) / 2;
    return query(2 * no, l, meio, ql, qr, seg) * query(2 * no + 1, meio + 1, r, ql, qr, seg);
}

void update(int no, int l, int r, int idx, int val, vector<int>& seg) {
    if (l == r) {
        seg[no] = val;
        return;
    }
    int meio = (l + r) / 2;
    if (idx <= meio) update(2 * no, l, meio, idx, val, seg);
    else update(2 * no + 1, meio + 1, r, idx, val, seg);
    seg[no] = seg[2 * no] * seg[2 * no + 1];
}

void solve() {
    int n, k; 
    while (cin >> n >> k) {
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> seg(4 * n);
        build(1, 0, n - 1, seg, p);

        string ans = "";
        while (k--) {
            char op; 
            cin >> op;

            if (op == 'P') {
                int l, r; 
                cin >> l >> r;
                l--; r--; 
                if (l > r) swap(l, r);

                int res = query(1, 0, n - 1, l, r, seg);
                if (res > 0) ans += '+';
                else if (res < 0) ans += '-';
                else ans += '0';
            } 
            else if (op == 'C') {
                int idx, val;
                cin >> idx >> val;
                idx--; 

                int sign_val = 0;
                if (val > 0) sign_val = 1;
                else if (val < 0) sign_val = -1;

                update(1, 0, n - 1, idx, sign_val, seg);
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}