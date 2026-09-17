#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>> n;
    int grupoAnterior = -1;
    for (int i= 0; i<n; i++){
        int num; cin >> num;
        int grupoAtual = (num-1)/10;
        if (grupoAtual < grupoAnterior){cout << "No\n"; return 0;}
        grupoAnterior = grupoAtual;
    }
    cout << "Yes\n";
    return 0;
}