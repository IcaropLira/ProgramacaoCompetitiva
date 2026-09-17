#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> moedas = {100,20,10,5,1};

    int c= 0;
    for (int i = 0; i<5; i++){
        c += n / moedas[i];
        n = n % moedas[i];

        
    }
    cout <<c << "\n";
    return 0;
}