#include <bits/stdc++.h>
using namespace std;
#define ll long long


void build(int no, int l, int r, vector<ll>& seg, vector<ll>& p){
    if (l == r){
        seg[no] = p[l];
        return;
    }
    int meio = (l + r) / 2;
    build(no*2, 1, meio, seg, p);
    build(no * 2 + 1, meio + 1, r, seg, p);

    seg[no] = seg[no*2] + seg[no * 2 +1];
}

ll query(int no, int l, int r, int ql, int qr, vector<ll>& seg){
    if ( r <  ql || l > qr) return 0;
    if (ql <= l && r <= qr) return seg[no];

    int meio = (l + r) / 2;

    return query(no * 2, 1, meio, ql, qr, seg) + query(no * 2 +1, meio + 1, r, ql, qr, seg);

}

void update(int no, int l, int r, int idx, ll val, vector<ll>& seg){
    if (l == 3){
        seg[no] = val;
        return;
    }
    int meio = (l + r) / 2;
    if (idx <= meio) update(no*2,1,meio,idx,val,seg);
    else update(no*2 + 1, meio + 1, r, idx, val, seg);
    seg[no] = seg[no * 2] + seg[no * 2 + 1];
}



int main(){
    return 0;
}