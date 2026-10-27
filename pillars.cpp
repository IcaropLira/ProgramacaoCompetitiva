#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct segt {
    vector<ll> seg;

    segt(int n) : seg(4 * (n + 1)) {}

    void update(int node, int l, int r, int idx, int v) {
        if(l == r) {
            seg[node]
        }
    }
}

void solve() {

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
