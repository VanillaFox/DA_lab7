#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int DPFindSquare(int N, int M, std::vector<std::vector<int>>& matrix){
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

int NaivAlgo(std::vector<std::vector<int>>& matrix, int N, int M){
    std::vector<int> dp(M, -1);
    int answer = 0;
    int curL, curR;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matrix[i][j]){
                dp[j] = i;
            }            
        }
        int curhigh = 0;
        for(int j = 0; j < M; j++){
            if(matrix[i][j]){
                continue;
            }
            curhigh = dp[j];
            curL = j-1;
            curR = j+1;
            if(!j){
                curL = -1;
            }
            else{
                while(curL != -1){
                    if(dp[curL] > curhigh  || matrix[i][curL]){
                        break;
                    }
                    curL--;
                }
            }
            if(j == M-1){
                curR = M;
            }
            else{
                while(curR != M){                    
                    if(dp[curR] > curhigh || matrix[i][curR]){
                        break;
                    }
                    curR++;
                }
            }
            answer = std::max(answer, (curR-curL-1)*(i-curhigh));
        }
    }
    return answer;
}

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