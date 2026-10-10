#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        long long x, y; cin >> x >> y;
        long long s = x + y;
        long long z = 0;
        for (int bit = 28; bit >= 0; bit--) {
            long long b = 1LL << bit;
            if (!(s & b)) continue;
            long long candidato = z | b;
            if (candidato <= x) z = candidato;
        }
        if ((z & (s - z)) != 0) {cout << (x ^ y) << ' ' << 0 << '\n';} 
        else {cout << s << ' ' << x - z << '\n';}
    }
}