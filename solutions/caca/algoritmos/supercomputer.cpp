#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct bit {
    vector<ll> b;

    void init(int n) {
        b.resize(n + 1);
    }

    void add(int i, int val, int n) {
        for(; i <= n; i += i & (-i)) {
            b[i] += val;
        }
    }

    ll query(int i) {
        ll ans = 0;
        for(; i > 0; i -= i & (-i)) {
            ans += b[i];
        }
        return ans;
    }

    ll query(int a, int b) {
        return query(a) - query(b - 1);
    }
};


void solve() {
    int n, q; cin >> n >> q;

    vector<int> nums(n + 1, 0);
    bit b;
    b.init(n);

    while(q--) {
        char type; cin >> type;
        if(type == 'F') {
            int a; cin >> a;
            if(nums[a] == 0) {
                nums[a] = 1;
                b.add(a, 1, n);
            }
            else {
                nums[a] = 0;
                b.add(a,-1,n);
            }
        }

        else {
            int l, r; cin >> l >> r;
            cout << b.query(r, l) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}

