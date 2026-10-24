#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q; cin >> n >> q;
    vector<int> nums(n);
    unordered_map<int, int> pos;
    for(int i =0; i<n; i++){int num; cin>> num; nums[i] = num;pos[num] = i;}
    vector<int> proximo(n);
    vector<int> anterior(n);
    for(int i=0; i<n; i++){
        if(i == 0) anterior[i] = -1;
        else anterior[i] = i-1;
        if(i == n-1) proximo[i] = -1;
        else proximo[i] = i+1;
    }
    int inicio = 0;
    int fim = n-1;
    while (q--){
        int num; cin>> num;
        int atual = pos[num];
        if (atual == fim) continue;
        if (anterior[atual] != -1) proximo[anterior[atual]] = proximo[atual];
        else inicio = proximo[atual];
        if(proximo[atual] != -1)anterior[proximo[atual]] = anterior[atual];
        anterior[atual] = fim;
        proximo[atual] = -1;
        proximo[fim] = atual;
        fim = atual;
    }
    int atual = inicio;
    while (atual != -1){
        cout << nums[atual] << " ";
        atual = proximo[atual];
    }
    cout << "\n";
    return 0;
}