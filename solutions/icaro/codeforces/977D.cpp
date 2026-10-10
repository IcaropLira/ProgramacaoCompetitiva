#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> nums(n); for(int i =0 ; i<n; i++){cin >> nums[i];}
    unordered_set<ll> conjunto(n);
    for(auto i: nums){conjunto.insert(i);}
    for(int i = 0; i<n; i++){
        vector<ll> ordemCerta;
        queue<ll> fila;     
        fila.push(nums[i]);
        unordered_set<int> visitados;
        visitados.insert(nums[i]);
        while(!fila.empty()){
            ll atual = fila.front();
            ordemCerta.push_back(atual);
            visitados.insert(atual);
            fila.pop();
            ll op1 = atual * 2;
            if (conjunto.contains(op1)){fila.push(op1);}
            if (atual % 3 == 0){
                if(conjunto.contains(atual /3))
                fila.push(atual / 3);}
            if(ordemCerta.size() == n) break;
        }
        if(ordemCerta.size() == n){for(auto i: ordemCerta){cout << i << " ";} cout<< "\n"; break;}
    }

    return 0;
}