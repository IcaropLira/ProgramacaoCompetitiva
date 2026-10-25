#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void build(int no, int l, int r, vector<ll>& a, vector<ll>& seg){
    if(l == r){
        seg[no] = a[l];
        return;
    }
    int meio = (l + r) / 2;
    build(no * 2, l, meio, a, seg);
    build(no * 2 + 1, meio + 1, r, a, seg);
    seg[no] = seg[no * 2] + seg[no * 2 + 1];
}

void propagar(int no, int l, int r, vector<ll>& seg, vector<ll>& lazy){
    if(lazy[no] == 0)
        return;

    seg[no] += lazy[no] * (r - l + 1);

    if(l != r){
        lazy[no * 2] += lazy[no];
        lazy[no * 2 + 1] += lazy[no];
    }

    lazy[no] = 0;
}

void update(int no, int l, int r, int ql, int qr, ll valor, vector<ll>& seg, vector<ll>& lazy){

    propagar(no, l, r, seg, lazy);

    if(r < ql || qr < l)
        return;
    if(ql <= l && r <= qr){
        lazy[no] += valor;
        propagar(no, l, r, seg, lazy);
        return;
    }

    int meio = (l + r) / 2;

    update(no * 2, l, meio, ql, qr, valor, seg, lazy);
    update(no * 2 + 1, meio + 1, r, ql, qr, valor, seg, lazy);

    seg[no] = seg[no * 2] + seg[no * 2 + 1];
}

ll query(int no, int l, int r, int ql, int qr,
         vector<ll>& seg, vector<ll>& lazy){

    propagar(no, l, r, seg, lazy);

    if(r < ql || qr < l)
        return 0;

    if(ql <= l && r <= qr)
        return seg[no];

    int meio = (l + r) / 2;

    return query(no * 2, l, meio, ql, qr, seg, lazy)
         + query(no * 2 + 1, meio + 1, r, ql, qr, seg, lazy);
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> seg(4 * n);
    vector<ll> lazy(4 * n);

    build(1, 1, n, a, seg);

    while(m--){

        int tipo;
        cin >> tipo;

        if(tipo == 1){

            int l, r;
            ll valor;

            cin >> l >> r >> valor;

            update(1, 1, n, l, r, valor, seg, lazy);
        }

        else{

            int l, r;
            cin >> l >> r;

            cout << query(1, 1, n, l, r, seg, lazy) << '\n';
        }
    }
}