#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct trie {
    
    struct node {
        int ch[2];
        int tam[2];

        node() {
            memset(ch, -1, sizeof(ch));
            memset(tam, 0, sizeof(tam));
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

            a[cur].tam[b]++;
            cur = a[cur].ch[b];
        }
    }

    void remove(int x) {
        int cur = 0;

        for(int i = 29; i >= 0; i--) {
            int b = (x >> i) & 1;

            int at = a[cur].ch[b];

            a[cur].tam[b]--;
            if(a[cur].tam[b] == 0) a[cur].ch[b] = -1;

            cur = at;
        }
    }

    ll query(int x) {
        int cur = 0;
        ll resp = 0;

        for(int i = 29; i >= 0; i--) {
            int b = (x >> i) & 1;

            if(a[cur].ch[b ^ 1] != -1) {
                resp |= (1 << i);
                cur = a[cur].ch[b^1];
            }

            else cur = a[cur].ch[b];
        }
        return resp;
    }
};

void solve() {
    int n; cin >> n;

    trie t;
    t.insert(0);
    while(n--) {
        string ty; cin >> ty;
        int x; cin >> x;

        if(ty == "+") t.insert(x);
        else if(ty == "-") t.remove(x);
        else cout << t.query(x) << '\n';
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
