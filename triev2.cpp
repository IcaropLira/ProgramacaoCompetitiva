#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct trie {
    
    struct node {
        bool end;
        int ch[10];
        int tam[10];

        node() {
            end = false;
            memset(ch, -1, sizeof(ch));
            memset(tam, 0, sizeof(tam));
        }
    };

    vector<node> a;
    int head = 1;

    trie (int _n)  : a(_n) {}

    void insert(string s) {
        int cur = 0;

        for(char c: s) {
            int pos = c - 'a';

            if(a[cur].ch[pos] == -1) {
                a[cur].ch[pos] = head++;
            }

            a[cur].tam[pos]++;
            cur = a[cur].ch[pos];
        }

        a[cur].end = true;
    }

    int verifica(string s) {
        int cur = 0;

        for(int i = 0; i < (int) s.size(); i++) {
            int pos = s[i] - 'a';

            if(a[cur].ch[pos] == -1) return 0;
        
            if(i == (int) s.size() - 1) return a[cur].ch[pos];

            cur = a[cur].ch[pos];
        }
    }

    bool verificasetem(string s) {
        int cur = 0;

        for(int i = 0; i < (int) s.size(); i++) {
            int pos = s[i] - 'a';

            if(a[cur].ch[pos] == -1) return false;
            if(a[cur].end) return true;
        }

        return false;
    }

}


struct triexor {
    
    struct node {
        bool end;
        int ch[2];

        node() {
            end = false;
            memset(ch, -1, sizeof(ch));
        }
    };

    vector<node> a;
    int head = 1;

    triexor() : a(1) {}

    void insert(int x) {
        int cur = 0;

        for(int i = 32; i >= 0; i--) {
            int b = (x >> i) & 1;

            if(a[cur].ch[b] == -1) {
                a.push_back(node());
            }

            cur = a[cur].ch[b];
        }

        a[cur].end = true;
    }

    int xor(int x) {
        int cur = 0;
        int resp = 0;

        for(int i = 32; i >= 0; i--) {
            int b = (x >> i) & 1;
            int rb = b ^ 1;

            if(a[cur].ch[rb] != -1) {
                rep |= (1 << i);
                cur = a[cur].ch[rb];
            }

            else {
                cur = a[cur].ch[b];
            }
        }
    }

};

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
