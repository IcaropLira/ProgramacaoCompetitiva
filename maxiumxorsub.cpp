#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct trie {
    
    struct node {
        bool end;
        int ch[2];

        node() {
            end = false;
            memset(ch, -1, sizeof(ch));
        }

    };

    int head = 1;
    vector<node> a;

    trie() : a(1) {}

    void insert(int x) {
        int cur = 0;

        for(int i = 29; i >= 0; i--) {
            int b = (x >> i) & 1;

            if(a[cur].ch[b] == -1) {
                a.push_back(node());
                a[cur].ch[b] = head++;
            }

            cur = a[cur].ch[b];
        }
    }

    ll cxor(int x) {
        int cur = 0;
        ll resp = 0;

        for(int i = 29; i >= 0; i--) {
            int b = (x >> i) & 1;
            int rb = b ^ 1;

            if(a[cur].ch[rb] != -1) {
                resp |= (1 << i);
                cur = a[cur].ch[rb];
            }

            else {
                cur = a[cur].ch[b];
            }
        }

        return resp;
    } 
};

void solve() {
    int n; cin >> n;

    vector<int> nums(n);

    trie t;

    vector<ll> pref(n + 1);

    t.insert(0);

    ll resp = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    ll p = 0;
    for(int x : nums) {
        p ^= x;
        resp = max(resp, t.cxor(p));
        t.insert(p);
    }

    cout << resp << '\n';

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
