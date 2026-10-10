#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ll long long
#define ql '\n'
using namespace std;

// usando como referencia a questao Supercomputer da lista de bit
vector<int> bit, p;

ll query(int pos) {
    ll soma = 0;

    while(pos > 0) {
        soma += bit[pos];
        pos -= pos & (-pos);
    }

    return soma; // retorna query do intervalo [1, pos]
}

ll query(int a, int b) {
    return query(b) - query(a - 1); // retorna query do intervalo [a, b]
}

void update(int pos, int n, int v) { // incrementa v no indice pos
    while(pos <= n) {
        bit[pos] += v;
        pos += pos & (-pos);
    }
}

void solve() {
    int n, q; cin >> n >> q;
    bit.resize(n + 1);
    p.resize(n + 1);

    while(q--) {
        char t; cin >> t;

        if (t == 'F') {
            int idx; cin >> idx;
            int v = (p[idx] == 0 ? 1 : -1);

            update(idx, n, v);
            p[idx] = !p[idx];
        }
        else {
            int a, b; cin >> a >> b;
            cout << query(a, b) << ql;
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t = 1;
    //cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}