#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int time = 0;
vector<int> tin;
vector<int> tout;
vector<vector<int>> adj;

struct bit {
    int n;
    vector<ll> b;

    bit(int n) : n(n), b(n+1, 0) {};

    void add(int i; int v) {
        for(; i <= n; i += i & (-i)) b[i] += v;
    }

    ll query(int i) {
        ll ans = 0;
        for(; i > 0; i -= i & (-i)) ans += b[i];

        return ans;
    }

    ll query(int a, int b) {
        return query(a) - query(b-1);
    }
}


void dfs(int v, int pr = -1) {
    time++;
    tin[v] = time;

    for(int ch : adj[v]) {
        if(ch == pr) continue;
        dfs(ch,v);
    }

    tout[v] = time;
}

void solve() {
    tin.assign();
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
