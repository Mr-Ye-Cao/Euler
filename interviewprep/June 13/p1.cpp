// medium https://leetcode.com/problems/triangle/submissions/

// g++ -Wall -Wextra -Wpedantic -std=c++11 -o test test.cpp
// ./test

#include <iostream>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    // initialize a 2-d array
    int rowNum = triangle.size(), colNum = triangle[triangle.size()-1].size();

    int dp[rowNum][colNum];

    for(int i = 0 ; i < rowNum ; i++){
        for(int j = 0 ; j < colNum ; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = triangle[0][0];

    for(int i = 1 ; i < rowNum ; i++){
        for(int j = 0 ; j < triangle[i].size() ; j ++){
            if(j == 0){
                // dp[i][j] = dp[i-1][j] + a_i[j];
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }else if(j == triangle[i].size() - 1){
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }else{
                // dp[i][j] = max(dp[i-1][j] + a_i[j], dp[i-1][j-1] + a_i[j];
                dp[i][j] = min(dp[i-1][j] + triangle[i][j], dp[i-1][j-1] + triangle[i][j]);
            }
        }
    }

    int result = INT_MAX;

    for(int i = 0 ; i < colNum ; i ++){
        cout<<dp[rowNum-1][i]<<endl;
        result = min(result, dp[rowNum-1][i]);
    }
    
    return result;
}

int main() {
    cout << "Hello, World!\n";

    vector<vector<int>> v;

    minimumTotal();

    return 0;
}