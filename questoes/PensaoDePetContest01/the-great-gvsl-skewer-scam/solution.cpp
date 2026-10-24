#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0; 
    vector<int> a(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // DP do Subset Sum
    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int v : a) {
        for (int s = sum; s >= v; s--) {
            if (dp[s - v]) {
                dp[s] = true;
            }
        }
    }

    int ans = INT_MAX;

    for (int s = 0; s <= sum; s++) {
        if (dp[s]) {
            ans = min(ans, abs(sum - 2 * s));
        }
    }

    cout << ans << "\n";

    return 0;
}