#include <bits/stdc++.h>
using namespace std;
#define ll long long


void build(int no, int l, int r, vector<ll>& seg, vector<ll>& p){
    if (l == r){
        seg[no] = p[l];
        return;
    }
    int meio = (l + r) / 2;
    build(no*2, l, meio, seg, p);
    build(no * 2 + 1, meio + 1, r, seg, p);

    seg[no] = seg[no*2] + seg[no * 2 +1];
}

ll query(int no, int l, int r, int ql, int qr, vector<ll>& seg){
    if ( r <  ql || l > qr) return 0;
    if (ql <= l && r <= qr) return seg[no];

    int meio = (l + r) / 2;

return query(no* 2, l, meio, ql, qr, seg)+ query(no * 2 + 1, meio + 1, r, ql, qr, seg);
}

void update(int no, int l, int r, int idx, ll val, vector<ll>& seg){
    if (l == r){
        seg[no] = val;
        return;
    }
    int meio = (l + r) / 2;
    if (idx <= meio) update(no*2,l,meio,idx,val,seg);
    else update(no*2 + 1, meio + 1, r, idx, val, seg);
    seg[no] = seg[no * 2] + seg[no * 2 + 1];
}



int main(){
    int n, m; cin >> n >> m;
    vector<ll> array(n);
    vector<ll> seg(4*n);

    for (int i= 0; i< n; i++){ll num; cin>> num; array[i] = num;}
    build(1, 0, n-1, seg, array);
    
    for (int i = 0; i < m; i++) {
    int op, a, b;
    cin >> op >> a >> b;

    if (op == 1) {a--;update(1, 0, n-1, a, b, seg);
    } else {a--;b--; cout << query(1, 0, n-1, a, b, seg) << '\n';
    }
}
    return 0;
}