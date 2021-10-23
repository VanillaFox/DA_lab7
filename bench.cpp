#include <iostream>
#include <vector>
#include <chrono>
#include "funcs.h"

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix;
    int dp, other;
    FillMatrix(n, m, matrix);

    auto start = std::chrono::steady_clock::now();
    other = NaivAlgo(matrix, n, m);
    auto end = std::chrono::steady_clock::now();
    std::cout << "NaivAlgo: " << other << std::endl;
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Time: " <<  elapsed_seconds.count() << std::endl;

    start = std::chrono::steady_clock::now();
    dp = DPFindSquare(n, m, matrix);
    end = std::chrono::steady_clock::now();
    std::cout << "DPAlgo: " << dp << std::endl;
    elapsed_seconds = end-start;
    std::cout << "Time: " <<  elapsed_seconds.count() << std::endl;
}