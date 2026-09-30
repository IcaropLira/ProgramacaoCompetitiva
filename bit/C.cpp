#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define ull unsigned long long

const int INT_INF = 1e6;
const ll INF = 1e9;
const ll MOD = 1e10 + 7;
const int LOG = 20;

struct bit{
    
    ll n;
    vector<ll> vec;

    bit(ll n): n(n), vec(n + 1) {}

    ll get_lsb(ll no){
        return no & (-no);
    }

    void update(ll no, ll val){
        while (no <= n) {
            vec[no] += val;
            no += get_lsb(no);
        }
    }

    ll prefix(ll no){
        ll res = 0;
        while (no > 0) {
            res += vec[no];
            no -= get_lsb(no);
        }
        return res;
    }
};

int main(){

    int n; cin >> n;

    while (n--){
        int m; cin >> m;
        vector<int> arr(m);
        for (int i = 0; i < m; i++){
            cin >> arr[i];
        }

        vector<int> sorted = arr;
        sort(all(sorted));

        bit b(m);
        ll res = 0;
        for (int i = 0; i < m; i++){
            int pos = lower_bound(all(sorted), arr[i]) - sorted.begin() + 1;
            
            ll qtd_pre = b.prefix(pos);

            res += i - qtd_pre;

            b.update(pos, 1);
        }

        cout << res << endl;
    }

    return 0;
}
