#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6;

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
        
        int head;
        vector<node> a;

        trie(int n) {
            head = 1;
            a.resize(n);
        }
        
        void insert(string s) {
            int cur = 0;

            for(char c : s) {
                int pos = c - '0';
                if(a[cur].ch[pos] == -1) {
                    a[cur].ch[pos] = head++;
                    a[cur].tam[pos] = 1;
                }

                else {
                    a[cur].tam[pos]++;
                }

                cur = a[cur].ch[pos];
            }

            a[cur].end = true;
        }

        bool verify(string s) {
            int cur = 0;

            for(char c : s) {
                int pos = c - '0';
                
                if(a[cur].end) return false;
                if(a[cur].ch[pos] == -1) return true;
                cur = a[cur].ch[pos];
            }

            return false;
        }

};

void solve() {
    int n; cin >> n;

    vector<string> nums(n);

    trie t(1e6); 

    for(int i = 0; i < n; i++) cin >> nums[i];

    bool resp = true;

    for(int i = 0; i < n; i++) {
        if(!t.verify(nums[i])) {
            resp = false;
            break;
        }
            t.insert(nums[i]);
    }
    
    if(resp) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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
