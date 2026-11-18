#include <bits/stdc++.h>
using namespace std;

using ll = long long;
bool check(ll num, ll k, ll x, vector<ll>& nums){
    ll c = 0;
    c+=  max((ll)0, nums[0] - num +1);
    for (int i = 0; i < (int) nums.size() -1; i++){
       c += max((ll) 0, nums[i+1] - nums[i] - 2 *num + 1);
    }
    c += max((ll)0,x -nums[nums.size()-1] - num + 1);
    return (c >=k);
}


void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    ll l = 0; ll r = x;
    ll meio;
    while (l < r){
        meio = l + (r-l+1)/2;
        if (check(meio,k,x, nums)) l = meio;
        else r = meio-1;
    }
    meio = l;
    if (meio == 0) {
        for (int i = 0; i < k; i++)
            cout << i << " ";
        cout << "\n";
        return;
    }
    vector<int> ans;
    for (int i = 0; i <= nums[0] - meio && (int)ans.size() < k; i++){
        ans.push_back(i);
    }
    for (int j = 0; j < n-1 && (int)ans.size() < k; j++){
        for (int i = nums[j]+meio + (meio == 0); i <= nums[j+1] - meio && (int)ans.size()< k; i++){
            ans.push_back(i);
        }
    }
    for (int i = nums.back() + meio; i<= x && (int)ans.size() < k; i++){
        ans.push_back(i);
    }
    for (int v: ans) cout << v << " ";
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
