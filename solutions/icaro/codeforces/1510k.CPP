#include <bits/stdc++.h>
using namespace std;

vector<int> bubble(){

}


int main(){
    vector<int> estado;
    queue<vector<int>> q;
    map<vector<int>,int> dist;

    int n; cin >> n;
    for (int i = 0; i<2*n;i++){
        int ent; cin >> ent;
        estado.push_back(ent);
    }
    vector<int> objetivo;
    objetivo = sort(estado.begin(), estado.end());

    while (!q.empty()){

        vector<int> v = q.front();
        q.pop();
        if (v == objetivo){
            cout << dist[v] << "\n";
            return 0;
        }
        vector<int> a = bubble(v);
        vector<int> b = reverse_bubble(v);
        
        if (!dist.count(a)){
            dist[a] = dist[v] + 1;
            q.push(a);
        }
        if (!dist.count(b)){
            dist[b] = dist[v] + 1;
            q.push(b);
        }

    }
    return 0;
}