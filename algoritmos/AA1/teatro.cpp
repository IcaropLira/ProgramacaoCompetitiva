#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,b,c;
    std::cin >> a >> b >> c;

    long long num1 = (a + c - 1) / c;
    long long num2 = (b + c -1) / c;

    long long out = num1 * num2;

    std::cout << out << endl;

    return 0;
}

