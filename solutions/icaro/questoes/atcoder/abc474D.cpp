#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin>> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i<n; i++){cin>> a[i];}
    for(int i = 0; i<n; i++){cin>> b[i];}
    int pos = -1;
    for(int i =0; i<n; i++){if(a[i] > b[i]){ pos = i;break;}}
    if (pos == -1){cout << "No\n"; return 0;}
    cout << "Yes\n";
    for(int i = 0; i < n; i++){
        if(i == pos) cout << 1000000000000000LL << " ";
        else cout << 1 << " ";
    }
    cout << "\n";
    return 0;
}