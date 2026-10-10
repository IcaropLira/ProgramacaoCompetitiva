#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<int> nums;
struct bit {
    vector<ll> b;

    void init() {
        b.resize(n + 1);
    }

    void add(int i, int v) {
        for(; i <= n; i += i & (-i)) {
            b[i] += v;
        }
    }

    ll query(int i) {
        ll ans = 0;
        for(; i > 0; i -= i & (-i)) {
            ans += b[i];
        }
        return ans;
    }
};


void solve() {
    int q; cin >> n >> q;

    bit bi;
    bi.init();

    nums.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        bi.add(i, nums[i]);
    }    

    while(q--) {
        int type, a, b; cin >> type >> a >> b;

        if(type == 2) {
            cout << bi.query(b) - bi.query(a-1) << endl;
        }
        else {
            bi.add(a, -nums[a]);
            nums[a] = b;
            bi.add(a, nums[a]);
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

