include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct trie {
    
    struct node {
        bool end;
        vector<ll> ch;
        vector<ll> tam;

        node() : end(false), ch(26, -1), tam(26, 0) {}
    };

    vector<node> nodes;
    trie(int n): nodes(n + 1) {}
    int head = 1;

    void insert(string &s) {
        int cur = 0;

        for(chr c : s) {
            int pos = c - 'a';
            if(nodes[cur].ch[pos] == -1) {
                nodes[cur].ch[pos] = head++;
                nodes[cur].tam[pos] = 1;
            }

            else{ 
                nodes[cur].tam[pos]++;
            }

            cur = nodes[cur].ch[pos];
        }

        nodes[cur].end = true;
    }

    int find(string s) {
        int cur = 0;

        for(int i = 0; i < (int) s.size(); i++) { 
            char c = s[i];
            int pos = c - 'a';
            if(nodes[cur].ch[pos] == -1) return 0;
            if(i == (int)s.size() - 1) return nodes[cur].tam[pos];
            cur = nodes[cur].ch[pos];
        }

        return 0;

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
