#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m; cin >> n >> m;

        vector<ll> a(n);

        for(int i=0;i<n;i++){ cin >> a[i];}

        priority_queue<ll> menores;

        ll soma = 0;
        ll resposta = -1e15;

        for(int i=0;i<n;i++){

            if(menores.size() == m-1){
                ll atual = m * a[i] - soma;
                resposta = max(resposta, atual);
            }

            menores.push(a[i]);
            soma += a[i];

            if(menores.size() > m-1){

                soma -= menores.top();
                menores.pop();
            }
        }

        cout << resposta << '\n';
    }

    return 0;
}