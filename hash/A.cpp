#include <bits/stdc++.h>
using namespace std;

using ll = long long;



void solve() {
    string n, m; cin >> n >> m;

    if (m.size() > n.size()) {
        cout << 0 << endl;
        return;
    }

    vector<int> h1(n.size() + 1);
    vector<int> h2(n.size() + 1);
    vector<int> pp1(n.size() + 1);
    vector<int> pp2(n.size() + 1);

    ll m1 = 1e9 + 7;
    ll m2 = 1e9 + 9;
    for (int i = 0; i < n.size(); i++) {
        int c = n[i] - 'a';
        h1[i + 1] = (n[i] * 30 + c) % m1;
        h2[i + 1] = (n[i] * 30 + c) % m2;
        pp1[i + 1] = (pp1[i] * 30) % m1;
        pp2[i + 1] = (pp2[i] * 30) % m2;
    }

    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < m.size(); i++) {
        int c = m[i] - 'a';
        p1 = (p1 * 30 + c) % m1;
        p2 = (p2 * 30 + c) % m2;
    }

    int ans = 0;

    for (int i = m.size(); i < n.size(); i++) {
        int r = i - 1;
        int l = i - m.size() - 1;
        if ((h1[r] - h1[l] * pp1[r - l + 1]) % m1 == p1) {
           if ((h2[r] - h2[l] * pp2[r - l + 1]) % m2 == p2) {
             ans += 1;
           } 
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

