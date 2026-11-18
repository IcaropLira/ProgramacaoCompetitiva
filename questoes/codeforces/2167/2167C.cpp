#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    bool par = false, impar = false;
    for (int i = 0; i < n; i++){
        int num; cin >> num;
        nums[i] = num;
        if (nums[i] % 2 == 0) par = true;
        else impar = true;
    }
   
    if (par && impar){
        sort(nums.begin(), nums.end());
    }
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << "\n";
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
