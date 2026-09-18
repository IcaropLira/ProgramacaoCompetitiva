#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int geral = 0;
    
    for (int i = 0; i < t; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        
        int contador = 0;

        if (a == 1){
            contador++;
        } if ( b == 1) {
            contador++;
        } if (c == 1) {
            contador++;
        }
        
        if (contador >= 2) {
            geral++;
        }

    }
    
    cout << geral << endl;
    return 0;
}

