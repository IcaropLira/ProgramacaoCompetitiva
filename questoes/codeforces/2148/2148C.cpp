#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int,int>> pontos;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        pontos.emplace_back(a,b);
    }
    int i = 0;
    int p = 0;
    int atual = 0;
    int pontuacao = 0;
    while (i < n && p <= m){
        int dist = pontos[i].first - p;
        if (atual == pontos[i].second){
            if (dist % 2 == 0) pontuacao += dist;
            else pontuacao += dist-1;
        }
        else{
            if (dist % 2 == 0) pontuacao += dist-1;
            else pontuacao += dist;
        }
        atual = pontos[i].second;
        p = pontos[i].first;
        i++;
    }
    if (p < m) pontuacao += m-p;
    cout << pontuacao << "\n";
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
