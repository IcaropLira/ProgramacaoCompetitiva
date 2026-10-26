#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct segt {
    vector<int> seg;

    segt(int n) : seg(4 * n) {}

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            seg[node] = max(val, seg[node]);
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid) update(node * 2, l, mid, idx, val);
        else update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    int query(int node, int l, int r, int lq, int rq) {
        if(l > rq || r < lq) return 0;
        if(l >= lq && r <= rq) return seg[node];

        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, lq, rq), query(node * 2 + 1, mid + 1, r, lq, rq));
    }
};


// seg vai ter tamanho 4 * (v + 1) onde v é o maior numero da lista;
// tem o intervalo [x - d, x + d];
// update da posicao x vai ser query(x -d, x + d) + 1;
void solve() {
    int n, d; cin >> n >> d;

    vector<int> nums(n);
    int v = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        v = max(v, nums[i]);
    }

    segt s(v + 1);

    for(int i = 0; i < n; i++) {
        int melhor = s.query(1, 1, v, max(nums[i] - d, 0), min(nums[i] + d, v));

        s.update(1, 1, v, nums[i], melhor + 1);
    }

    cout << s.query(1,1,v,1,v) << endl;
}

int main() {

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}
