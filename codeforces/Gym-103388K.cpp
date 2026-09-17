#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, d, m; 
    cin >> t >> d >> m;

    vector<int> ref(m);
    for (int i = 0; i < m; i++) {
        cin >> ref[i];
    }

    if (m == 0) {
        cout << (d >= t ? "Y" : "N") << "\n";
        return 0;
    }

    bool conseguiu_dormir = false;

    if (ref[0] >= t) {
        conseguiu_dormir = true;
    }

    for (int i = 1; i < m; i++) {
        if (ref[i] - ref[i-1] >= t) { 
            conseguiu_dormir = true;
        }
    }

    if (d - ref.back() >= t) {
        conseguiu_dormir = true;
    }

    if (conseguiu_dormir) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }

    return 0;
}