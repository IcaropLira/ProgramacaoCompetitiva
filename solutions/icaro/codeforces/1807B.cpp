#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; cin >> q;
    while (q--){
        int n; cin >> n;
        int pares = 0;
        int impares = 0;
        for(int i=0; i<n;i++){int num; cin>> num; if(num % 2 ==0){pares += num;}else{impares += num;}}
        cout << (pares > impares? "YES\n": "NO\n");
    }
    return 0;
}