#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "funcs.h"

int main(){
    int n, m;
    std::vector<std::vector<int>> matrix;
    std::cin >> n >> m;
    FillMatrix(n, m, matrix);
    std::cout << DPFindSquare(n, m, matrix) << std::endl;
}