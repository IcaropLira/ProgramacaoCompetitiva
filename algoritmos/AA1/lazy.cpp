#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void build(int l, int r, int node) {
    if (l == r){
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, node * 2);
    build(mif + 1, r, node * 2 + 1);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void push(int ini, int fim, int node){
    if (lazy[node] != 0) {
        seg[node += lazy[node] * (fim - ini + 1)
    }

    if (start != end){
        lazy[node * 2] += lazy[node];
        lazy[ * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << t << endl;
    }

    return 0;
}

