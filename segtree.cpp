#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ll long long
#define endl "\n"
using namespace std;

int n;
struct segt {
    vector<array<int, 3>> seg;

    void init(int n) {
        seg.resize(4 * (n+1));
    }

    void build(int l, int r, int node, const string &nums) {
        if(l == r) {
            if(nums[l - 1] == ')') seg[node][2]++;
            else seg[node][0]++;
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2, nums);
        build(mid + 1, r, node* 2 + 1, nums);

        int qntdParenteses = min(seg[node * 2][0], seg[node * 2 + 1][2]);
        
        seg[node][1] = seg[node * 2][1] + seg[node * 2 + 1][1] + qntdParenteses * 2;
        seg[node][0] = seg[node * 2][0] + seg[node * 2 + 1][0] - qntdParenteses;
        seg[node][2] = seg[node * 2 + 1][2] + seg[node * 2][2] - qntdParenteses;
    }

    void update(int l, int r, int idx, int val, int node) {
        if(l == r) {
            seg[node][1] = val;
            return;
        } 

        int mid = (l + r) / 2;

        if(idx <= l) update(l, mid, idx, val, node * 2);
        else update(mid + 1, r, idx, val, node * 2 + 1);

        seg[node][1] = seg[node * 2][1] + seg[node * 2 + 1][1];
    }

    array<int, 3> query(int l, int r, int lq, int rq, int node) {
        if(l > rq || r < lq) return {0,0,0};
        if(l >= lq && r <= rq) return seg[node];

        int mid = (l + r) / 2;

        array<int, 3> noes =  query(l, mid, lq, rq, node * 2); 
        array<int, 3> nodir = query(mid + 1, r, lq, rq, node * 2 + 1);

        int q = min(noes[0], nodir[2]);
        int qntd = noes[1] + nodir[1];

        qntd += q * 2;

        return {noes[0] + nodir[0] - q, qntd ,noes[2] + nodir[2] - q};
    }
};

void solve() {
    string parenteses; cin >> parenteses;
    int q; cin >> q;

    segt b;
    b.init(parenteses.size());
    b.build(1,parenteses.size(),1,parenteses);

    while(q--) {
        int l, r; cin >> l >> r;

        cout << b.query(1,parenteses.size(),l,r,1)[1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}

