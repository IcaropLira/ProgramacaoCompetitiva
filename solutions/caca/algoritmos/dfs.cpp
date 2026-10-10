#include <bits/stdc++.h>
#include <deque>
#define all(v) v.begin(), v.end()
#define endl "\n"
using namespace std;
using ll = long long;

void dfs(int no, int target, set<int> &visitados, vector<vector<int>> &grafo) {
    visitados.insert(no);
    for(int filho : grafo[no]) {
        if(!visitados.count(filho)) {
            dfs(filho, target, visitados,grafo);
        }
    }
}

void dfsiterativo(int no, set<int> visitados, vector<vector<int>> grafo) {
    vector<int> pilha;
    pilha.push_back(no);

    while(!pilha.empty()) {
        int v = pilha.back();
        pilha.pop_back();
        
        if(visitados.count(v)) continue;
        visitados.insert(v);

        for(int fi : grafo[v]) {
            if(!visitados.count(fi)) {
                pilha.push_back(fi);
            }
        }
    }
}


void bfs(int no, set<int> &visitados, vector<vector<int>> &grafo) {
    deque<int> fila;
    fila.push_back(no);
    visitados.insert(no);

    while(!fila.empty()) {
        int v = fila.front();
        fila.pop_front();

        for(int fi : grafo[v]) {
            if(!visitados.count(fi)) {
                fila.push_back(fi);
                visitados.insert(fi);
            }
        }
    }
}

vector<int> bfsdist(int no, vector<vector<int>> &grafo, int n) {
    deque<int> fila;
    fila.push_back(no);
    vector<int> dist(n + 1, -1);

    while(!filha.empty()) {
        int v = fila.front();
        fila.pop_front();

        for(int fi : grafo[v]) {
            if(dist[fi] == -1) {
                fila.push_back(fi);
                dist[fi] = dist[v] + 1;
            }
        }
    }
    return dist;
}

int dfsPontoMaisDistante(int no, vector<vector<pair<int,int>>> &grafo, ll d, vector<ll> &dist) {
     dist[v] = d;

     for(auto [a,b]: grafo[v]) {
        dfs(a, grafo, dist[v] + b, dist);
     }
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
    
