#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

struct bit {
    vector<ll> b;

    void init(int n) {
        b.resize(n + 1);
    }

    void add(int i, int val, int n) {
        for(; i <= n; i += i & (-i)) b[i] += val;
    }

    ll query(int i) {
        ll ans = 0;
        for(; i > 0; i -= i & (-i)) ans += b[i];
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

