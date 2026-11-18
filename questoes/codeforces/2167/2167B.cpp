#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    unordered_map<char, int> freqS, freqT;
    for (int i = 0; i < n; i++){
        freqS[s[i]]++;
        freqT[t[i]]++;
    }
    bool pode = true;
    for (const auto& [s, f] : freqS){
        if (freqT[s] != f){
            pode = false;
            break;
        }
    }
    cout << (pode ? "YES\n" : "NO\n");
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
