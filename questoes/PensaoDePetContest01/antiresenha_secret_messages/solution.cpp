#include <bits/stdc++.h>
using namespace std;

char shiftBack(char c, int x) {
    return char('A' + (c - 'A' - x + 26) % 26);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = sqrt(s.size());

    vector<vector<char>> mat(n, vector<char>(n));

    int pos = 0;
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n; row++) {
            mat[row][col] = s[pos++];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((i + j) % 2 == 1) {
                swap(mat[i][j], mat[j][i]);

                if (islower(mat[i][j]))
                    mat[i][j] = toupper(mat[i][j]);
                else
                    mat[i][j] = tolower(mat[i][j]);

                if (islower(mat[j][i]))
                    mat[j][i] = toupper(mat[j][i]);
                else
                    mat[j][i] = tolower(mat[j][i]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                mat[i][j] = shiftBack(mat[i][j], i + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (char)toupper(mat[i][j]);
        }
    }

    cout << '\n';

    return 0;
}