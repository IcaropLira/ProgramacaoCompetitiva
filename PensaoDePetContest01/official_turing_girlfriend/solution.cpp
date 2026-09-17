#include <bits/stdc++.h>
using namespace std;

struct Event {
    long long l, r, d;
    char dir;
};

long long L, R;
vector<Event> events;

bool check(long long x) {

    for (auto &e : events) {

        long long move = min(x, e.d);

        if (e.dir == 'L') {
            // Novo intervalo: [l-move, r-move]
            // Precisa estar completamente antes de Larissa
            if (e.r - move >= L)
                return false;
        } 
        else {
            // Novo intervalo: [l+move, r+move]
            // Precisa estar completamente depois de Larissa
            if (e.l + move <= R)
                return false;
        }
    }

    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cin >> L >> R;

    events.resize(n - 1);

    for (auto &e : events) {
        cin >> e.l >> e.r >> e.d >> e.dir;
    }

    long long lo = 0;
    long long hi = 1e9;

    while (lo < hi) {

        long long mid = lo + (hi - lo) / 2;

        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    if (check(lo))
        cout << lo << '\n';
    else
        cout << -1 << '\n';

    return 0;
}