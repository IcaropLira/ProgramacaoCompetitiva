#include <bits/stdc++.h>
#include <bitset>
using namespace std;
using ll = long long;

struct bitt {

    void add(int v, int i) {
        for(; i < n; i & (-i)) {
            bit[i] += v;
        }
    }

    ll query(int pos) {
        ll ans = 0;
        for(; pos > 0; pos -= pos & (-pos)) ans += bit[pos];
        return ans;
    }
};

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

