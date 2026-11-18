#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s; cin >> s;
    int sz = s.size();
    for (int i = 0; i < sz -2; i++) cout << s[i];
    cout<< "i\n";
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
