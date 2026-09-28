#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

vector<vector<ll>> adj;
vector<vector<ll>> p;
vector<ll> dep;
const int LOG = 20;

void build(int no, int pai){
	for (int i = 1; i < LOG; i++){
		p[no][i] = p[p[no][i - 1]][i - 1];
	}
	for (ll ch: adj[no]){
		if (ch == pai) continue;
		p[ch][0] = no;
		dep[ch] = dep[no] + 1;
		build(ch, no);
	}
}

ll lca(int a, int b){
	if (dep[a] > dep[b]){
		swap(a, b);
	}

	ll dist = dep[b] - dep[a];
	
	for (int i = 0; i < LOG; i++){
		if (dist & (1LL << i)) {
			b = p[b][i];
		}
	}

	if (a == b){
		return a;
	}

	for (int i = LOG - 1; i >= 0; i--){
		if (p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n; cin >> n;
	adj.resize(n + 1);
	p.resize(n + 1, vector<ll>(LOG));
	dep.resize(n + 1);

	for (int i = 1; i < n; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	build(1, 1);
	int m; cin >> m;
	for (int i = 0; i < m; i++){
		int x, y, z; cin >> x >> y >> z;
		ll lca_xy = lca(x, y);
		ll dist_xy = dep[x] + dep[y] - 2 * dep[lca_xy];
		if (z >= dist_xy) {
			cout << y << endl;
			continue;
		}
		if (dep[x] - dep[lca_xy] > z){
			swap(x, y);
			z = dist_xy - z;
		}
		for (int i = 0; i < LOG; i++){
			if (z & (1LL << i)) {
				x = p[x][i];
			}
		}

		cout << x << endl;

	}
	return 0;
}
