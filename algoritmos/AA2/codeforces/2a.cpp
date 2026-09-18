// incopleta
#include <bits/stdc++.h>

#define ql "\n"
#define all(u) v.begin(), v.end()
#define ll long long
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    map<string, int> myDic;

    int n; cin >> n;
    vector<pair<string, int>> lista;

    for (int i = 0; i < n; i++){
        string linha;
        int m;

        cin >> linha >> m;

        myDic[linha] += m;
        lista.push_back({linha, m});
    }

    string contemMaior = "";
    int maior = -1e9;

    for (auto[a, b] : myDic){
        if(b > maior){
            maior = b;
            contemMaior = a;
        } else if (b == maior) {
            for (int i = lista.size() - 1; i > -1; i--){
                if (lista[i].first == contemMaior && lista[i].second >= 0){
                    maior = b;
                    contemMaior = a;
                } else if (lista[i].first == a && lista[i].second >= 0){
                    break;
                }
            }
        }
    }
    
    cout << contemMaior << endl;
    return 0;
}