#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];

        vector<int> pais(n+1);
        for(int i=0;i<=n;i++) pais[i]=i;

        auto find = [&](int x)->int{
            while(pais[x]!=x){
                pais[x]=pais[pais[x]];
                x=pais[x];
            }
            return x;
        };

        set<int> conjunto;

        for(int k=1;k<=n;k++){
            int ak = a[k];
            
            for (int j = 0; j < ak; j++) { 
                ll l = 1LL * j * k;
                ll r = min(1LL * (n - 1), 1LL * (j + 1) * k - 1);
                if (l >= n) break; 
                int L = (int)l;
                int R = (int)r;
                auto it = conjunto.lower_bound(L);
                if (it != conjunto.end() && *it <= R) continue;
                int p = find(L); if (p <= R) { conjunto.insert(p);
                pais[p] = p + 1;
                }
                }
                ll l = 1LL * ak * k;
                ll r = min(1LL * (n - 1), 1LL * (ak + 1) * k - 1);
                if (l < n && l <= r) { int R = (int)r;
                int p = find((int)l);
                while (p <= R) { 
                    pais[p] = p + 1; 
                    p = find(p);                            
                }
            }
        }


            cout << conjunto.size() << '\n';

            for (int x : conjunto)
                cout << x << ' ';

            cout << '\n';


}
}