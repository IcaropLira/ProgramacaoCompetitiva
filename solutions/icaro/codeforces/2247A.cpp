#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int positivos = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x == 1)
                positivos++;
        }

        if (n % 2 == 1) {
            cout << "NO\n";
        }
        else if (positivos % 2 == (n / 2) % 2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}