#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int r, int c, vector<vector<int>>& triangle, int n){
        if (r == n - 1) return triangle[r][c];

        int down = triangle[r][c] + f1(r+1, c, triangle, n);
        int diag = triangle[r][c] + f1(r+1, c+1, triangle, n);

        return min(down, diag);
    }   
    
    // memoization
    int f2(int r, int c, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
        if (r == n - 1) return triangle[r][c];
        if (dp[r][c] != -1) return dp[r][c];
        int down = triangle[r][c] + f2(r+1, c, triangle, n, dp);
        int diag = triangle[r][c] + f2(r+1, c+1, triangle, n, dp);

        return dp[r][c] = min(down, diag);
    }   

    // tabulation
    int f3(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for (int i=n-2; i>=0; i--){
            for (int j=i; j>=0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diag);
            }
        }

        return dp[0][0];
    }

    // space optimization
    int f4(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<int> below(n);
        for (int j=0; j<n; j++){
            below[j] = triangle[n-1][j];
        }

        for (int i=n-2; i>=0; i--){
            vector<int> cur(n);
            for (int j=i; j>=0; j--){
                int down = triangle[i][j] + below[j];
                int diag = triangle[i][j] + below[j+1];
                cur[j] = min(down, diag);
            }
            below = cur;
        }

        return below[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // recursion
        // return f1(0, 0, triangle, n);

        // memoization
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f2(0, 0, triangle, n, dp);

        // tabulation
        // return f3(triangle);

        // space optimization
        return f4(triangle);
    }
};