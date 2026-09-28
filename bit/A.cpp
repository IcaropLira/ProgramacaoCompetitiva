#include <bits/stdc++.h>
using namespace std;

using ll = long long;


struct bit{
    vector<ll> l;
    int tam;

    ll get_lsb(ll valor){
        return valor & (-valor);
    }

    void build(int n, vector<ll> &arr){
        tam = n;
        l.resize(n + 1);
        for (int i = 1; i <= tam; i++){
            add(i, arr[i]);
        }
    }

    void add(int pos, int val){
        while (pos <= tam){
            l[pos] += val;
            pos += get_lsb(pos);
        }
    }

    ll query(int s, int e){
        ll res = 0;

        while (e > 0){
            res += l[e];
            e -= get_lsb(e);
        }
        
        while (s > 0){
            res -= l[s];
            s -= get_lsb(s);
        }

        return res;
    }

    void update(int pos, int val, vector<ll> &arr){
        int valor = val - arr[pos];
        arr[pos] += valor;
        add(pos, valor);
    }

};

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    bit b;
    b.build(n, arr);

    for (int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        if (x == 1){
            b.update(y, z, arr);
        } else {
            cout << b.query(y - 1, z) << endl;
        }
    }
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