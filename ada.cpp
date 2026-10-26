#include <bits/stdc++.h>
using namespace std;
using ll = long long;



struct trie {
    struct node {
        bool end;
        ll ch[26];
        ll tam[26];

        node() {
            end = false;
            memset(ch, -1, sizeof(ch));
            memset(tam, 0, sizeof(tam));
        }
    };

    int head = 1;
    vector<node> a;

    trie(int n) : a(n) {}

    void insert(string s) {
        int cur = 0;

        for(char c : s) {
            int pos = c - 'a';

            if(a[cur].ch[pos] == -1) {
                a[cur].ch[pos] = head++;
            }

            a[cur].tam[pos]++;
            cur = a[cur].ch[pos];
        }

        a[cur].end = true;
    }

    int verify(string s) {
       int cur = 0;

       for(int i = 0; i < (int) s.size(); i++) {
            int pos = s[i] - 'a';

            if(a[cur].ch[pos] == -1) return 0;
            if(i == (int) s.size() - 1) return a[cur].tam[pos];
            cur = a[cur].ch[pos];
       }
       
       return 0;
    }

};

void solve() {
    int n, q; cin >> n >> q;

    trie t(1e6 + 10);
    while(n--) {
        string s; cin >> s;
        t.insert(s);
    }

    while(q--) {
        string pref; cin >> pref;

        cout << t.verify(pref) << '\n';
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
