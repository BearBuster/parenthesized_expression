#include "Function.h"

int main() {
    int result;
    pNode Tree;
    string s = {"(1+1)*(3+3)"};
    Tree = makeTree(s);
    print(Tree);
    cout << calc(Tree);
    return 0;
}
