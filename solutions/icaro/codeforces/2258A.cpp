#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> freq(m + 1);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            freq[x]++;
        }
        vector<int> suf(m + 2);

        for (int x = m; x >= 1; x--) { suf[x] = suf[x + 1] + freq[x];}

        int resposta = 0;

        for (int x = 1; x <= m; x++) {
            int atual = suf[x];
            if (2 * x <= m)  atual += freq[2 * x];
            resposta = max(resposta, atual);
        }

        cout << resposta << '\n';
    }

    return 0;
}