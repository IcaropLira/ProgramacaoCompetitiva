#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> nums;
    int menor = 1e9;
    cout << "AAAAA\n";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        if (nums[i] < menor) menor = nums[i];
    }
    cout << "AAA\n";
    for (int i = 2; i < 1e9; i++){
        if (gcd(i, menor) == 1){
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
    
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
