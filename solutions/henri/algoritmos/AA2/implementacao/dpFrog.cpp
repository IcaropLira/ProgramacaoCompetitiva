// dp do sapo que pula de 1 ate k, ele começa em 1 e tem q saber quantas formas ele pode chegar em n

#include <bits/stdc++.h>
using namespace std;

using ll = long long;




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> k >> n;
    vector<ll> dp(n, 0);
    vector<ll> pre(n, 0);
    dp[1] = 1;
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= k; j++){
            if(i + j < n){
                dp[i+j] += dp[i];
            } else {
                break;
            }
        }
    
    dp[1] = pre[i] = 1;
    for (int i = 2; i <= n; i++){
        if ( i - k <= 0){
            dp[i] = pre[i-1];
            pre[i] = pre[i-1] + dp[i];
        } else{
            dp[i] = pre[i-1] - pre[i-k-1];
            pre[i] = pre[i-1] + dp[i];
        }
    }
    }

    cout << dp[n] << endl;

}