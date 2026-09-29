#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) static_cast<int>((x).size())

const int INF  = 1e9;
const ll LINF  = 1e18;
const int MOD  = 1e9 + 7;

struct BIT{

    vector<int> bit;
    int tam;

    int get_lsb(int v){
        return v & (-v);
    }

    void build(int n, vector<int> &arr){
        bit.resize(n + 1);
        tam = n;
        for (int i = 1; i <= n; i++){
            add(i, arr[i]);
        }
    }

    void add(int pos, int v){
        while (pos <= tam){
            bit[pos] += v;
            pos += get_lsb(pos);
        }
    }

    int query(int s, int e){
        int res = 0;

        while (e > 0){
            res += bit[e];
            e -= get_lsb(e);
        }

        s-=1;
        while (s > 0){
            res -= bit[s];
            s -= get_lsb(s);
        }

        return res;
    }
};

void solve(int tc) {
    int n, m; cin >> n >> m;

    vector<int> arr(n + 1, 0);
    BIT bit;
    bit.build(n, arr);

    while (m--){
        char s; cin >> s;
        if (s == 'F'){
            int x; cin >> x;
            if (bit.query(x, x)) {
                bit.add(x, -1);
            } else {
                bit.add(x, 1);
            }
        } else {
            int x, y; cin >> x >> y;
            cout << bit.query(x, y) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    
    for (int tc = 1; tc <= t; ++tc) {
        solve(tc);
    }

    return 0;
}