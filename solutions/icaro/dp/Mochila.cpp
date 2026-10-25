#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<vector<int>> dp;
vector<int> peso;
vector<int> valor;

void mochila() {
    for (int i = 0; i<= n; i++){
        for (int w = 0; w <= w; w++){
            if (i == 0 || w ==0){
                dp[i][w] = 0;
            }
            else if (peso[i] <= w){
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-peso[i]] + valor[i]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
}


void solve() {

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
