#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> moedas(n);
    for (int i=0; i<n; i++){
        int num; cin >> num;
        moedas[i] = num;
    }
    long long INF = 1e8;
    vector<long long> dp(m+1);
    for (int i=0; i<= m; i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    sort(moedas.begin(), moedas.end());
    for(int i = 1; i<=m; i++){
        for (int moeda: moedas){
            if (moeda > i) break;
            if (dp[i-moeda]+ 1 < dp[i]){
                dp[i] = dp[i-moeda] + 1;
            }
        }
    }
    if (dp[m] == INF){
        cout << -1 << "\n";
    }
    else cout << dp[m] << "\n";

    return 0;
}