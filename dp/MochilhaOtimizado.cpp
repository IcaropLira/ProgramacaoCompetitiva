#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll dp[200005];
int n, W;
int peso[105], valor[105];


void mochila(){
    for (int i = 1; i <= n; i++){
        for (int w = W; w>=peso[i]; w--){
            dp[w] = max(dp[w],dp[w-peso[i]] + valor[i]);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> W;

    for (int i =1; i <= n; i++){
        cin >> peso[i] >> valor[i];
    }
    mochila();
    cout << dp[W] <<"\n";

    return 0;
}
