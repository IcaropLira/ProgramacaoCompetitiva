#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<vector<int>> soma;
vector<vector<int>> valor;

void dp() {
    for (int y = 0; y< n; y++){
        for (int x = 0; x <n; x++){
            soma[y][x] = max(soma[y][x > 0? x-1 : 0], soma[y > 0?y-1:0][x]) + valor[y][x];
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    soma.resize(n, vector<int>(n));
    valor.resize(n,vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> valor[i][j];
        }
    }
    soma[0][0] = 0;
    dp();
    
    cout << soma[n-1][n-1] << "\n";

    return 0;
}
