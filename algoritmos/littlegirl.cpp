#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

int n;
vector<ll> nums;
vector<ll> lazy;

struct seglazy{
    vector<ll> seg;

    void init() {
        seg.resize(4 * (n + 1));
        lazy.resize(4 * (n + 1));
        seg.build(1,n,1);
    }

    void build(int l, int r, int node) {
        if(l == r) {
            seg[node] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, node * 2);
        build(mid + 1, r, node * 2 + 1);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    void(update
    
}

void solve() {

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

