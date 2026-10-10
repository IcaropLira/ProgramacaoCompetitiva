#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t;
    cin >> t;

    std::set<char> mySet = {};

    for (auto i = 0u; i < t.size(); i++){
        mySet.insert(t[i]);
    }

    int tam = mySet.size();
    if (tam % 2 == 0){
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }

    return 0;
}

