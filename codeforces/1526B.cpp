#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> dp(2000);
    dp[0] = 1;
    for (int i = 0; i < 2000; i++){
        if (i % 11 == 0){
            dp[i] = 1;
        }
        else{
            //if i - > 0;
        }
    }

    for (int i = 0; i< n; i++){
        int m; cin >> m;
        
    }
    return 0;
}