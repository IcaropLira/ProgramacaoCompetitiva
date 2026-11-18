#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x; cin >> n >> x;
    if (x % 2 == 0) cout << 0 << "\n";
    else cout << n*x - n*(x-1) << "\n";
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
