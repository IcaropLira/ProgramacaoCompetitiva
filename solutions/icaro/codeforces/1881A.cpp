#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s;

        int ans = 0;

        while (x.find(s) == string::npos && x.size() < n + m) {
            x += x;
            ans++;
        }

        if (x.find(s) != string::npos)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }
}