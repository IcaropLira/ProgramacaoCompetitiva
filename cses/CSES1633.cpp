#include <bits/stdc++.h>
using namespace std;
int main(){
    int MOD = 1e9+7;
    int n; cin >> n;
    vector<int> dp(n+1);
    vector<int> dado  = {1,2,3,4,5,6};
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<= n; i++){
        int temp = 0;
        for (int d: dado){
            if (i -d >= 0 && dp[i-d] != 0){
                temp = (temp + dp[i-d]) % MOD;
            }
        }
        dp[i] = temp % MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}