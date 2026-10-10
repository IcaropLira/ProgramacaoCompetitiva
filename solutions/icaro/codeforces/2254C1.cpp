#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while (q--){
        int n; cin >> n;
        string a, b; cin >> a >> b;
        int a1p = 0;
        int a1i = 0;
        int b1p = 0;
        int b1i = 0;
        for (int i = 0; i < n; i+= 2){if (a[i] == '1') a1p++; if (b[i] == '1') b1p++;}
        for (int i = 1; i < n; i+= 2){if (a[i] == '1') a1i++; if (b[i] == '1') b1i++;}
        cout << (a1p == b1p & a1i == b1i? "YES\n": "NO\n");
    }


    return 0;
}
