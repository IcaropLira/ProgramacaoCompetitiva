#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> lx(n);
    vector<int> ly(m);
    for (int i = 0; i < n; i++) cin >> lx[i];
    for (int i = 0; i < m; i++) cin >> ly[i];
    cout << n+m << "\n";
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
