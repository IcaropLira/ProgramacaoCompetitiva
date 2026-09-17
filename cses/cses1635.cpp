#include <bits/stdc++.h>

using namespace std;

int main(){
    int MOD = 1e9 + 7;
    int n, m; cin >> n >> m;
    vector<int> moedas(n);
    for (int i = 0; i < n; i++){
        int n; cin >> n;
        moedas[i] = n;
    }
    vector<int> dp(m+1);
    dp[0] = 1;
    for (int i = 1; i<= m; i++){
        for (int moeda: moedas){
            if (i >= moeda){
                dp[i] = (dp[i] + dp[i-moeda]) % MOD;
            }
        }
    }
    cout << dp[m] << "\n";
    return 0;
}