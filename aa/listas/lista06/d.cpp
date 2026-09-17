#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define br '\n';
#define f first;
#define s second

typedef long long ll;


void dfs(int no, unordered_map<int, set<int>>& grafo, set<int>& visitados){
	visitados.insert(no);
	
	for (auto vizinho : grafo[no]){
		if (!visitados.count(vizinho)){
			dfs(vizinho, grafo, visitados);	
		}
	}

}

int main(){

	int n, m; cin >> n >> m;

	unordered_map<int, set<int>> grafo;

	for (int i = 0; i < m; i++){
		int v, u; cin >> v >> u;
		grafo[v].insert(u);
		grafo[u].insert(v);
	}


	set<set<int>> conjuntos;
	
	for (int no = 1; no <= n; no++){
		
		set<int> visitados;
		dfs(no, grafo, visitados);
		conjuntos.insert(visitados);
	}
	int maior = 0;

	for (auto n : conjuntos){
		if (n.size() > maior){
			maior = n.size();
		}

	}
	cout << maior;


	return 0;
}