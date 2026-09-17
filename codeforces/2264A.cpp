#include <bits/stdc++.h>

using namespace std;

int main(){

    int t; cin >> t;

    while(t--){

        int n; cin >> n;

        vector<int> p(n+1);

        for(int i=1;i<=n;i++){ cin >> p[i];}
        vector<int> errados;
        for(int i=1;i<=n;i++){
            if(p[i] != i) errados.push_back(i);
        }

        int l = 0;
        int r = errados.size()-1;

        while(l < r){
            swap(p[errados[l]], p[errados[r]]);
            l++;
            r--;
        }

        bool ok = true;

        for(int i=1;i<=n;i++){

            if(p[i] != i){
                ok = false;
                break;
            }

        }
        cout << (ok? "YES\n": "NO\n");
    }

    return 0;
}