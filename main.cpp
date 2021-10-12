#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void FillMatrix(int N, int M, std::vector<std::vector<int>>& matrix){
    std::vector<int> cur;
    char p;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> p;
            cur.push_back(p-48);
        }
        matrix.push_back(cur);
        cur.clear();
    }
}

int FindSquare(int N, int M, std::vector<std::vector<int>>& matrix){
    std::stack<int> stack;
    std::vector<int> dp(M, -1), k1(M), k2(M);
    int answer = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matrix[i][j]){
                dp[j] = i;
            }
        }
        
        while(!stack.empty()){
            stack.pop();
        }
        for(int j = 0; j < M; j++){
            while(!stack.empty() && dp[stack.top()] <= dp[j]){
                stack.pop();
            }
            k1[j] = stack.empty() ? -1 : stack.top();
            stack.push(j);
        }

        while(!stack.empty()){
            stack.pop();
        }
        for(int j = M-1; j >= 0; j--){
            while(!stack.empty() && dp[stack.top()] <= dp[j]){
                stack.pop();
            }
            k2[j] = stack.empty() ? M : stack.top();
            stack.push(j);
        }

        for(int j = 0; j < M; j++){
            answer = std::max(answer, (i - dp[j]) * (k2[j] - k1[j] - 1));    
        }
    }

    return answer;
}

int main(){
    int n, m;
    std::vector<std::vector<int>> matrix;
    std::cin >> n >> m;
    FillMatrix(n, m, matrix);
    std::cout << FindSquare(n, m, matrix) << std::endl;
}