#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void build(int no, int l, int r, vector<ll>& seg, vector<ll>& p){
    if (l == r){
        seg[no] = p[l];
        return;
    }
    int meio = (l+ r)/2;
    build(no*2, l, meio, seg, p);
    build(no*2+1, meio+1, r, seg, p);
    seg[no] = seg[no*2] + seg[no*2+1];
}

ll query(int no, int l, int r, int ql, int qr, vector<ll>& seg){
    if (r < ql || qr < l) return 0;

    if (ql <=l && qr >= r){
        return seg[no];
    }
    int meio = (l + r)/ 2;
    return query(no*2, l, meio, ql, qr, seg) + query(no*2+1, meio + 1, r, ql, qr, seg);
}

void update(int no, ll valor, int idx, int l, int r, vector<ll>& seg){
    if (l == r){
        seg[no] = valor;
        return;
    }
    int meio = (l + r)/2;
    if (idx <= meio) update(no*2, valor, idx, l, meio, seg);
    else update(no*2+1, valor, idx, meio +1, r, seg);
    seg[no] = seg[no*2]+ seg[no*2+1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<ll> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    vector<ll> seg(4*n);
    build(1,0, n-1, seg, p);
    while(m--){
        int op; cin >> op;
        if (op == 1){
            int u, k; cin >> k >> u;
            k--;
            update(1,u,k,0,n-1,seg);
        }
        else{
            int a, b; cin >> a >> b;
            a--; b--;
            cout << query(1, 0,n-1,a, b, seg) << "\n";
        }

    }

    return 0;
}

