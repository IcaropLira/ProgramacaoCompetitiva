#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct trie {

    struct node {
        bool end;
        int ch[2];
        int tam[2];

        node() {
            end = false;
            memset(ch, -1, sizeof(ch));
            memset(tam, 0, sizeof(ch));
        }
    };
    
    int head;
    vector<node> a;

    trie(int n) {
        head = 1;
        a.resize(1);
    }

    void insert(int x) {
        int cur = 0;

        for(int i = 32 - 1; i >= 0; i--) {
            int b = (x >> i) & 1;

            if(a[cur].ch[b] == -1) {
                a.push_back(node());
                a[cur].ch[b] = head++;
            }

            a[cur].tam[b]++;
            cur = a[cur].ch[b];
        }

        a[cur].end = true;
    }

    ll query(int x) {
        int cur = 0;
        ll resp = 0;

        for(int i = 31; i >= 0; i--) {
            int b = (x >> i) & 1;
            int bitreversed = b ^ 1;

            if(a[cur].ch[bitreversed] != -1) {
                resp |= (1 << i); 
                cur = a[cur].ch[bitreversed];
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

    vector<ll> nums(n);

    trie t(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        t.insert(nums[i]);
    }

    ll resp = 0;

    for(int i = 0; i < n; i++) {
        resp = max(resp, t.query(nums[i]));
    }

    cout << resp << '\n';


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
