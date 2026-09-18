#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

using ll = long long;

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 0; i < t; i++){
        string j = "";

        cin >> j;

        if (j.size() > 10){
            cout << j[0] << j.size() -2 << j[j.size() -1] << endl;
        } else{
            cout << j << endl;
        }

    }

    return 0;
}

