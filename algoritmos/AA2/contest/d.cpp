#include <bits/stdc++.h>
using namespace std;

using ll = long long;




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    while (n--){
        string linha; cin >> linha;
        string out;

        int k = string.length(linha);
        for (int i = 0; i < k -1; i++){
            if (linha[i] == 'u' && linha[i+1] == 's'){
                out += 'i';
                i++;
            } else {
                out += linha[i];
            }
        }
        cout << out << endl;
    }

}