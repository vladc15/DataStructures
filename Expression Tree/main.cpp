#include <fstream>
#include <string>

#include "ExpressionTree.h"

std::ifstream fin("input.in");
std::ofstream fout("output.out");


int main() {
    /// (*(-3 1)(+2 5))
    /// spatii doar intre numere
    std::string expression;
    std::getline(fin, expression);
    ExpressionTree expressionTree(expression);
    fout << expressionTree.result();

    /**
     (+(*(-6 2) 3) 5)
    (/(-(*8 2) 10)(+3 1))

    (*(+3 4)(+5 6))

    (/7 (*4 2))

    (*(-3 1)(+2 5))
     */
    return 0;
}
