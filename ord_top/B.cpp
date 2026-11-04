#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()
vector<vector<int>> adj;
vector<int> in;

void solve() {
    int n, m; cin >> n >> m;

    priority_queue<int> fila;
    vector<int> ans;
    adj.resize(n + 1);
    in.resize(n + 1);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        in[y] += 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!in[i]) { 
            fila.push(-i);
        }
    }

    if (fila.empty()) {
        cout << "Sandro fails." << endl;
        exit(0);
    }
    else {
        while (!fila.empty()) {
            int top = -fila.top();
            ans.push_back(top);
            fila.pop();
            for (int ch: adj[top]) {
                in[ch] -= 1;
                if (in[ch] == 0) {
                    fila.push(-ch);
                }
            }
        }
    }

    if (ans.size() < n) cout << "Sandro fails." << endl;
    else {
        for (int n: ans) cout << n << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

