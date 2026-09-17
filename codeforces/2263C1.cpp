#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);

        vector<int> parent(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;

        auto find = [&](int x)->int{
            while(parent[x]!=x){
                parent[x]=parent[parent[x]];
                x=parent[x];
            }
            return x;
        };

        set<int> inSet;

        for(int k=1;k<=n;k++){
            int ak = a[k];
            // required blocks j = 0 .. ak-1
            for(int j=0;j<ak;j++){
                long long l = (long long)j*k;
                long long r = min((long long)(n-1), (long long)(j+1)*k - 1);
                if(l > n-1) break;
                int L=(int)l, R=(int)r;
                auto it = inSet.lower_bound(L);
                if(it!=inSet.end() && *it<=R) continue;
                int p = find(L);
                if(p<=R){
                    inSet.insert(p);
                    parent[p]=p+1;
                }
            }
            // forbidden block j = ak
            {
                long long l = (long long)ak*k;
                long long r = min((long long)(n-1), (long long)(ak+1)*k - 1);
                if(l<=n-1 && l<=r){
                    int R=(int)r;
                    int p = find((int)l);
                    while(p<=R){
                        parent[p]=p+1;
                        p = find(p);
                    }
                }
            }
        }

        printf("%d\n",(int)inSet.size());
        bool first=true;
        for(int x: inSet){
            if(!first) putchar(' ');
            printf("%d",x);
            first=false;
        }
        putchar('\n');
    }
}