#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void build(int no, int l, int r, vector<ll>& seg, vector<ll>& p){
    if (l == r){
        seg[no] = p[l];
        return;
    }
    int meio = (l+r)/2;
    build(no*2, l, meio, seg, p);
    build(no*2+1, meio+1, r, seg, p);
    seg[no] = seg[no*2] + seg[no*2+1];
}
void propagar(int no, int l, int r, vector<ll>& seg, vector<ll>& lazy){
    if (lazy[no] == 0){
        return;
    }
    seg[no] += lazy[no] * (r-l+1);
    
    if (l!=r){
        lazy[no*2] += lazy[no];
        lazy[no*2+1] += lazy[no];
    }
    lazy[no] = 0;
}

void update(int no, int l, int r, int ql, int qr,ll valor, vector<ll>& seg, vector<ll>& lazy){
    propagar(no, l, r, seg, lazy);
    if (qr < l || ql > r){
        return;
    }
    if (ql<=l && qr >=r){
        lazy[no] += valor;
        propagar(no, l, r, seg, lazy);
        return;
    }
    int meio = (l+r)/2;
    update(no*2, l, meio, ql, qr, valor, seg, lazy);
    update(no*2+1, meio+1, r, ql, qr, valor, seg, lazy);
    seg[no] = seg[no*2] + seg[no*2+1];
}


ll query(int no, int l, int r, int ql, int qr, vector<ll>& seg, vector<ll>& lazy){
    propagar(no, l, r, seg, lazy);
    if (ql > r || qr < l){
        return 0;
    }
    if (ql <= l && qr >=r){
        return seg[no];
    }
    int meio = (l+r)/2;
    return query(no*2, l, meio, ql, qr, seg, lazy) + query(no*2+1, meio + 1, r, ql, qr, seg, lazy);
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<ll> p(n+1);
    vector<ll> seg(4*n);
    vector<ll> lazy(4*n);


    for (int i = 1; i <= n; i++) cin >> p[i];
    
    build(1, 1, n, seg, p);

    while(m--){
        int op; cin >> op;
        if (op == 1){
            int l, r; ll valor;
            cin >> l >> r >> valor;
            update(1, 1, n, l, r, valor, seg, lazy);
        }
        else {
            int pos; cin >> pos;
            cout << query(1, 1, n, pos, pos, seg, lazy)<< "\n";
        }
    }

    return 0;
}

