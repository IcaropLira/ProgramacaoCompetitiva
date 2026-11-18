#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s; cin >> s;
    bool tem = false;
    for (int i = 0; i <(int) s.size()-1; i++){
        if (s[i] == s[i+1]){
            tem = true;
            break;
        }
    }
    cout << (tem? 1: (int) s.size()) << "\n";
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
