#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int lis(vector<int>& a){
    vector<int> fim;
    for (int x: a){
        auto it = lower_bound(fim.begin(),fim.end(),x);
        if (it == fim.end()) fim.push_back(x);
        else *it = x;
    }
    return (int)fim.size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << lis(a) << "\n";


    return 0;
}
