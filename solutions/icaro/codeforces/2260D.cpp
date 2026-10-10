#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int n;
        string s;
        cin >> n >> s;
        if (s[0] == '0' || s.find("00") != string::npos) {
            cout << -1 << '\n';
            continue;
        }
        bool tem = false;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0' && s[i - 1] != '0') {
                tem = true;
                break;
            }
        }
        if (!tem) { cout << 1 << '\n'; continue; }
        int ans = 2;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') { i++; continue; }
            int j = i;
            while (j < n && s[j] == s[i])
                j++;
            int len = j - i;
            if (i > 0 && j < n && s[i - 1] != '0' && s[j] != '0' && len % 2 == 0)
                ans = 3;
            i = j;
        }
        cout << ans << '\n';
    }
}