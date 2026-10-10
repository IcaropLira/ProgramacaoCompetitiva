#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

struct BIT {
    
    vector<ll> bit;
    ll s;
    
    BIT(ll n): s(n), bit(n + 1, 0) {}

    ll get_lsb(ll n){
        return n & (-n);
    }

    void add(ll n, ll val){
        while (n <= s) {
            bit[n] += val;
            n += get_lsb(n);
        }
    }

    ll sum(ll n){
        ll res = 0;
        while (n > 0){
            res += bit[n];
            n -= get_lsb(n);
        }
        return res;
    }
};


void solve() {
    int n; cin >> n;
    BIT bit(n);
    vector<pair<ll, ll>> p(n);
    vector<ll> b(n);

    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        p[i] = {a, b};
    }

    sort(all(p));

    for (int i = 0; i < n; i++){
        b[i] = p[i].second;
    }

    vector<ll> sorted = b;
    sort(all(sorted));

    ll ans = 0;
    for (int i = 0; i < n; i++){
        int pos = lower_bound(all(sorted), b[i]) - sorted.begin() + 1;

        ll qtd = bit.sum(pos);

        ans += i - qtd;

        bit.add(pos, 1);
    }

    cout << ans << endl;
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

