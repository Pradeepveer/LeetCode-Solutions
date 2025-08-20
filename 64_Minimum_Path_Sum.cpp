#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int r, int c, vector<vector<int>>& grid){
        if (r == 0 && c == 0) return grid[0][0];
        if (r < 0 || c < 0) return INT_MAX;

        int left = grid[r][c];
        int temp = f1(r, c-1, grid);
        if (temp == INT_MAX) left = temp;
        else left += temp;

        int up = grid[r][c];
        temp = f1(r-1, c, grid);
        if (temp == INT_MAX) up = temp;
        else up += temp;

        return min(left, up);
    }

    // memoization
    int f2(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if (r == 0 && c == 0) return grid[0][0];
        if (r < 0 || c < 0) return INT_MAX;
        if (dp[r][c] != -1) return dp[r][c];

        int left = grid[r][c];
        int temp = f2(r, c-1, grid, dp);
        if (temp == INT_MAX) left = temp;
        else left += temp;

        int up = grid[r][c];
        temp = f2(r-1, c, grid, dp);
        if (temp == INT_MAX) up = temp;
        else up += temp;

        return dp[r][c] = min(left, up);
    }

    // tabulation
    int f3(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i == 0 && j == 0) continue;
                int left = grid[i][j];
                if (j > 0) left += dp[i][j-1];
                else left = INT_MAX;

                int up = grid[i][j];
                if (i > 0) up += dp[i-1][j];
                else up = INT_MAX;
                dp[i][j] = min(left, up);
            }
        }

        return dp[m-1][n-1];
    }

    // space optimization
    int f4(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n);

        for (int i=0; i<m; i++){
            vector<int> cur(n, 0);
            for (int j=0; j<n; j++){
                if (i == 0){
                    if (j == 0) cur[j] = grid[0][0];
                    else cur[j] = grid[0][j] + cur[j-1];
                }
                else if (j == 0) cur[j] = prev[j] + grid[i][j];
                else{
                    int left = cur[j-1] + grid[i][j];
                    int up = prev[j] + grid[i][j];
                    cur[j] = min(left, up);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // recursion
        // return f1(m-1, n-1, grid);

        // memoization
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return f2(m-1, n-1, grid, dp);

        // tabulation
        // return f3(grid);

        // space optimization
        return f4(grid);
    }
};