#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(), v.end()
#define ql "\n"

using namespace std;
const int N = 2e5 + 10, LOG = 20;

int dep[N];
int p[N][LOG];
vector<vector<int>> adj(n+1);

void dfs_build(int v, int pr, int d = 1) {
    //in[v] e o out[v] servem pra saber quando entrou e saiu da dfs, pra ter um outro jeito de calcular se é ancestral ou nao
    //se u for ancestral de v, in[u] <= in[v] && out[v] <= out[u];
    dep[v] = d;
    for(int i = 1; i < LOG; i++) {
        p[v][i] = p[p[v][i-1]][i-1];
    }

    for(int fi : adj[v]) {
        if(fi == pr) continue; // ignorar o pai
        p[fi][0] = v;
        dfs(fi, v, d + 1);
    }
}

int lca(int v, int u) {
    if(dep[v] < dep[u]) swap(v,u); //considerando o v sempre o mais fundo;
    //pra nn fazer um if com o mesmo codigo, mesma ideia da dsu

    int dist = dep[v] - dep[u]; // diferenca de altura

    for(int i = 0; i < LOG; i++){
        if(dist & (1 << i)){ //dou o jump em potencia de 2; 1 << 0 = 1, 1 << 1 = 10 = 2 ...;
            v = p[v][i]; //atualizo a altura do meu no;
        }
    }

    if(u == v) return v; //se os dois forem iguais, quer dizer q ja é o LCA

    for(int i = LOG - 1; i >= 0; i--) {
        if(p[v][i] != p[u][i]) { //deixo na distancia = 1 pra no final eu so retornar o pai deles pelo p[v][0], pq ja como os dois sao filhos do mesmo pai e tao na msm distancia, vai ser o mesmo;
            v = p[v][i]; //ajeita a altura
            u = p[u][i]; //ajeita a altura
        }
    }

    return p[v][0]; //retorna o pai/LCA

    
}

int disttotal(int v, int u) {
    return dep[v] + dep[u] - 2 * dep[lca(u,v)]; //pega a distancia total de um ponto pro outro (subtrai 2 * lca(u,v) porque vai fazer o caminho de ir pra la e voltar duas vzs; 
}

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

