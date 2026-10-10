#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        if (k < n || k > 2 * n - 1) {
            cout << -1 << '\n';
            continue;
        }

        int r = 2 * n - k;

        vector<vector<int>> a(n, vector<int>(n, 0));

        int valor = 1;

        for (int i = 0; i < r; i++) {
            a[i][i] = valor++;
        }

        for (int i = r; i < n; i++) {
            a[i][r - 1] = valor++;
        }

        for (int j = r; j < n; j++) {
            a[0][j] = valor++;
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (a[i][j] == 0) {
                   a[i][j] = valor++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}