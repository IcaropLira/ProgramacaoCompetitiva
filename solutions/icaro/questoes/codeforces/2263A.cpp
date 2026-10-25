#include <bits/stdc++.h>
using namespace std;

int main() {

    int t; cin >> t;

    while (t--) {

        int n; cin >> n;
        int uns = 0;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 1) uns++;
        }
        if (uns >= (n + 1) / 2) cout << "Bessie\n";
        else cout << "Elsie\n";
    }

    return 0;
}