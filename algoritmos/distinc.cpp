#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;

    map<ll, int> pos;
    int l = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(pos.count(x) && pos[x] >= l) {
            l = pos[x] + 1;
        }
        pos[x] = i;
        ans += (i - l + 1);
    }

    cout << ans << endl;

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

