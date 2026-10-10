#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        long long d = y - x;
        long long ans = 0;

        long long qtd = min(k, max(0LL, d - x + 1));

        for (long long i = 0; i < qtd; i++) {
            ans += d % (x + i);
        }

        ans += (k - qtd) * d;

        cout << ans << '\n';
    }
}