#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()
struct BIT{
    vector<ll> bit;
    ll n;

    BIT(ll n): n(n), bit(n+1) {}

    void add(ll no, ll val){
        while (no <= n){
            bit[no] += val;
            no += no & -no;
        }
    }

    ll sum(ll no) {
        ll res = 0;
        while (no > 0){
            res += bit[no];
            no -= no & -no;
        }
        return res;
    }
};

void solve() {
    ll n; cin >> n;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    BIT bit(n);

    vector<ll> sorted = arr;
    sort(all(sorted));

    ll res = 0;
    for (ll i = 0; i < n; i++){
        ll pos = lower_bound(all(sorted), arr[i]) - sorted.begin() + 1;
        ll inv = bit.sum(pos - 1);

        res += i - inv;

        bit.add(pos, 1);
    }

    cout << res << endl;
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

