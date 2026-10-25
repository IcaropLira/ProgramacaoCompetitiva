#include "testlib.h"
#include <cmath>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // Aceita caracteres maiúsculos E minúsculos ([a-zA-Z])
    std::string s = inf.readToken("[a-zA-Z]{1,1000000}", "s");
    
    inf.readEoln();
    inf.readEof();

    int len = static_cast<int>(s.length());

    // Valida se o tamanho da string é um quadrado perfeito (N x N)
    int n = static_cast<int>(std::round(std::sqrt(len)));
    ensuref(n * n == len, "O tamanho da string (%d) precisa ser um quadrado perfeito (N^2).", len);

    return 0;
}