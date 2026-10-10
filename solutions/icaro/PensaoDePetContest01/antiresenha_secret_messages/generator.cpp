#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

string encrypt(string s) {
    int n = sqrt((int)s.size());

    vector<vector<char>> mat(n, vector<char>(n));

    int pos = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = s[pos++];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                mat[i][j] = char(
                    'A' + (mat[i][j] - 'A' + i + 1) % 26
                );
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if ((i + j) % 2 == 1) {

                swap(mat[i][j], mat[j][i]);

                mat[i][j] = tolower(mat[i][j]);
                mat[j][i] = tolower(mat[j][i]);
            }
        }
    }


    string ans;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            ans += mat[i][j];
        }
    }

    return ans;
}


int main(int argc, char* argv[]) {

    registerGen(argc, argv, 1);

    int n = rnd.next(1, 50);

    string original = "";

    for (int i = 0; i < n * n; i++) {
        original += char('A' + rnd.next(0, 25));
    }


    cout << encrypt(original) << '\n';

    return 0;
}