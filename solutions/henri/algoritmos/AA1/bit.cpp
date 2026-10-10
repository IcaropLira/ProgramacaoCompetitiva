#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void bit(){
    vector<ll> l;

    ll get_lsb(ll valor){
        return valor & (-valor);
    }

    void build(int num, vector<ll> &arr){
        l.resize(num);
    }

    ll query(int s, int e){
        ll res = 0;

        while (e > 0){
            res += l[s];
            e -= get_lsb(s);
        }

        while (s > 0){
            res -= l[s];
            s -= get_lsb(s);
        }

        return res;
    }

    void update(int pos, int val){
    }
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

