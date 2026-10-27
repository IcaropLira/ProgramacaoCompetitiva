#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

struct bitt {
    vector<ll> b;

    bitt(int n) : b(n + 1) {}

    void add(ll i, ll v) {
        for(; i < (int) b.size(); i += i & (-i)) b[i] = (v + b[i]) % MOD;
    }

    ll query(ll i) {
        ll ans = 0;

        for(; i > 0; i -= i & (-i)) ans = (b[i] + ans) % MOD;

        return ans % MOD;
    }
};

void solve() {
    int n; cin >> n;

    bitt b(n);

    vector<ll> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<ll> aux = nums;

    sort(all(aux));

    aux.erase(unique(all(aux)), aux.end());
    

    for(int i = 0; i < n; i++) {
        nums[i] = lower_bound(all(aux), nums[i]) - aux.begin() + 1;        
    }
  

    for(int i = 0; i < n; i++) {
        ll melhor = b.query(nums[i] - 1);
        b.add(nums[i], melhor + 1);
    }

    cout << b.query(n) << '\n';
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
