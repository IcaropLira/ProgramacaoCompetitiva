#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

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
    int n; cin >> n;
    vector<int> nums(n+1);

    for(int i = 1; i <= n; i++) cin >> nums[i];
    bit b;
    b.init(n);

    ll resp = 0;

    for(int i = 1; i <= n; i++) {
        resp += b.query(n) - b.query(nums[i] - 1);
        b.add(nums[i], 1, n);
    }

    cout << resp << endl;
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

