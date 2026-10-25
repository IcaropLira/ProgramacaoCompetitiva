#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // Inicializa o gerador usando os argumentos passados no script
    registerGen(argc, argv, 1);

    // Argumentos do script:
    // opt<int>(1) -> valor de N
    // opt<int>(2) -> valor máximo que cada elemento a[i] pode ter
    int n = opt<int>(1);
    int max_a = opt<int>(2);

    // Imprime N
    cout << n << "\n";

    // Gera e imprime os N elementos
    for (int i = 0; i < n; i++) {
        int val = rnd.next(1, max_a);
        cout << val << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}