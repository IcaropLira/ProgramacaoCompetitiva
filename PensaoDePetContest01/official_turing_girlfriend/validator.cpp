#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(2, 200000, "n");
    inf.readEoln();

    inf.readInt(1, 1000000000, "L");
    inf.readSpace();
    inf.readInt(2, 1000000000, "R");
    inf.readEoln();

    for (int i = 0; i < n - 1; i++) {
        inf.readInt(1, 1000000000, "l");
        inf.readSpace();

        inf.readInt(2, 1000000000, "r");
        inf.readSpace();

        inf.readInt(1, 1000000000, "d");
        inf.readSpace();

        inf.readToken("(L|R)", "dir");
        inf.readEoln();
    }

    inf.readEof();
}