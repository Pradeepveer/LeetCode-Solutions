#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // recursion
    int f(int r, int c, vector<vector<int>>& obstacleGrid){
        if (r >= 0 && c >= 0 && obstacleGrid[r][c] == 1) return 0;
        if (r == 0 && c == 0) return 1;
        if (r < 0 || c < 0) return 0;
        int up = f(r-1, c, obstacleGrid);
        int left = f(r, c-1, obstacleGrid);
        
        return up + left;
    }

    // memoization
    int f(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        if (r >= 0 && c >= 0 && obstacleGrid[r][c] == 1) return dp[r][c] = 0;
        if (r == 0 && c == 0) return 1;
        if (r < 0 || c < 0) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        int up = f(r-1, c, dp, obstacleGrid);
        int left = f(r, c-1, dp, obstacleGrid);
        
        return dp[r][c] = up + left;
    }

    // tabulation
    int f(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        dp[0][0] = 1;
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) continue;
                int up = 0, left = 0;
                if (i>0) up = dp[i-1][j];
                if (j>0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }

        return dp[r-1][c-1];
    }

    // space optimization
    int f(int r, int c, vector<vector<int>>& obstacleGrid){
        vector<int> prev(c, 0);
        for (int i=0; i<r; i++){
            vector<int> cur(c, 0);
            for (int j=0; j<c; j++){
                if (obstacleGrid[i][j] == 1) cur[j] = 0;
                else if (i == 0 && j == 0){
                    cur[j] = 1;
                }

                else{
                    int up = 0; int left = 0;
                    if (i>0) up = prev[j];
                    if (j>0) left = cur[j-1];
                    cur[j] = up + left;
                }
            }
            prev = cur;
        }

        return prev[c-1];
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // recursion return f(m-1, n-1, obstacleGrid);

        // memoization
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return f(m-1, n-1, dp, obstacleGrid);
    
        // tabulation
        // vector<vector<int>> dp(m, vector<int>(n));
        // return f(m, n, dp, obstacleGrid);

        // space optimization
        return  f(m, n, obstacleGrid);    
    }
};