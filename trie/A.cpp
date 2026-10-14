#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct TRIE{
    struct NODE {
        vector<int> ch;
        int fim;
        int tam;

        NODE() {
            for (int i = 0; i < 10; i++) {
                ch[i] = -1;
            }
            fim = 0;
            tam = 0;
        }
    }

    vector<NODE> nodes;
    int head;

    void init(n) {
        nodes.resize(n);
        head = 1;
    }

    void insert(string s) {
        int cur = 0;
        for (char c: s) {
            int num = c - '0';
            if (nodes[cur].ch[num] == -1) {
                nodes[cur].ch[num] = head;
                head += 1;
                nodes[cur].ch[num].tam = 0;
            }
            nodes[cur].ch[num].tam++;
            cur = nodes;
        }
    }
}
                    
                

void solve() {
    int n; cin >> n;
    vector<string> numeros(n);
    for (int i = 0; i < n; i++){
        cin >> numeros[i];
    }

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

