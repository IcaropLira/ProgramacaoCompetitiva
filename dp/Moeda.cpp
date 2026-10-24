#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;
const int N = 2e5+5;
int DP[N];
bool visitados[N];
vector<int> moedas;
int primeiro[N]; //Podemos declarar outro array que indica para cada soma de dinheiro a primeira moeda em uma solução ótima.
                 //Depois disso podemos usar para imprimir as moedas que aparecem em uma solução ótima para a soma n.
                 //é só ir subtraindo o valor da moeda e dizendo qual é o primeiro daquela até chegar em 0.
                 //uma vez que tenha solução, claro.

int contagem[N];

void dp(){
    DP[0] = 0;
    for (int i =1; i <= N; i++){
        for (auto c : moedas){
            if (i-c>= 0 && DP[i-c]+1 < DP[i]){
                DP[i] = DP[i-c]+1;
                primeiro[i] = c;
            }
        }
    }
}

void SeqMoedas(int x){
    if (DP[x] == INF) {
        cout << "IMPOSSÍVEL\n";
        return;
    }
    while (x >0){
        cout << primeiro[x] << " ";
        x -= primeiro[x];
    }
    cout << "\n";
}

void QuantidadeDeSolucoes(){
    contagem[0] = 1;
    for (int i = 1; i < N; i++){
        for (auto c : moedas){
            if (i-c >=0){
                contagem[i] += contagem[i-c];
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < N; i++) DP[i] = INF;
    for (int i =0; i < n; i++) {
        int x; cin >> x;
        moedas.push_back(x);
    }
    
    dp();
    cout << DP[m] << "\n";

    SeqMoedas(m);
    QuantidadeDeSolucoes();
    cout << contagem[m] << "\n";

    return 0;
}
