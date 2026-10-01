#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(vector<ll> &prefix) {
    int n; cin >> n;
    cout << prefix[n] << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    vector<ll> prefix(2e5 + 1);

    for(int i = 1; i <= 2e5; i++) {
        int num = i;
        prefix[i] += prefix[i-1];
        while(num > 0) {
            prefix[i] += num % 10;
            num = num / 10;
        }
    }

    while (t--) {
        solve(prefix);
    }

    return 0;
}

