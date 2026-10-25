#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void update(int pos, ll valor, int n, vector<ll>& bit){

    while(pos <= n){
        bit[pos] += valor;
        pos += pos & -pos;
    }
}

ll query(int pos, vector<ll>& bit){

    ll soma = 0;

    while(pos > 0){
        soma += bit[pos];
        pos -= pos & -pos;
    }

    return soma;
}

ll query(int l, int r, vector<ll>& bit){

    return query(r, bit) - query(l - 1, bit);
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<ll> bit(n + 1);

    for(int i = 1; i <= n; i++){

        ll x;
        cin >> x;

        update(i, x, n, bit);
    }

    while(m--){

        int tipo, l, r;
        cin >> tipo >> l >> r;

        if(tipo == 1){

            update(l, r, n, bit);
        }

        else{

            cout << query(l, r, bit) << '\n';
        }
    }
}