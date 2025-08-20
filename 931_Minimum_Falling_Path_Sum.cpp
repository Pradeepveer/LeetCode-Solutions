#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int r, int c, vector<vector<int>>& matrix, int n){
        if (c < 0 || c >= n) return INT_MAX;
        if (r == 0) return matrix[0][c];

        int up = matrix[r][c];
        int temp = f1(r-1, c, matrix, n);
        if (temp == INT_MAX) up = temp;
        else up += temp;

        int upleft = matrix[r][c];
        temp = f1(r-1, c-1, matrix, n);
        if (temp == INT_MAX) upleft = temp;
        else upleft += temp;

        int upright = matrix[r][c];
        temp = f1(r-1, c+1, matrix, n);
        if (temp == INT_MAX) upright = temp;
        else upright += temp;

        return min(up, min(upleft, upright));
    }

    // memoization
    int f2(int r, int c, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp){
        if (c < 0 || c >= n) return INT_MAX;
        if (r == 0) return matrix[0][c];
        if (dp[r][c] != -1) return dp[r][c];

        int up = matrix[r][c];
        int temp = f2(r-1, c, matrix, n, dp);
        if (temp == INT_MAX) up = temp;
        else up += temp;

        int upleft = matrix[r][c];
        temp = f2(r-1, c-1, matrix, n, dp);
        if (temp == INT_MAX) upleft = temp;
        else upleft += temp;

        int upright = matrix[r][c];
        temp = f2(r-1, c+1, matrix, n, dp);
        if (temp == INT_MAX) upright = temp;
        else upright += temp;

        return dp[r][c] = min(up, min(upleft, upright));
    }

    // tabulation
    int f3(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }

        for (int i=1; i<n; i++){
            for (int j=0; j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int upright = matrix[i][j];
                if (j+1 < n) upright += dp[i-1][j+1];
                else upright = INT_MAX;

                int upleft = matrix[i][j];
                if (j-1 >= 0) upleft += dp[i-1][j-1];
                else upleft = INT_MAX;
                
                dp[i][j] = min(up, min(upright, upleft));
            }
        }

        int ans = INT_MAX;
        for (int j=0; j<n; j++){
            ans = min(ans, dp[n][j]);
        }

        return ans;
    }

    // space optimization
    int f4(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<int> prev(n);
        vector<int> cur(n);

        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j];
        }

        for (int i=1; i<n; i++){
            for (int j=0; j<n; j++){
                int up = matrix[i][j] + prev[j];
                int upright = matrix[i][j];
                if (j+1 < n) upright += prev[j+1];
                else upright = INT_MAX;

                int upleft = matrix[i][j];
                if (j-1 >= 0) upleft += prev[j-1];
                else upleft = INT_MAX;
                
                cur[j] = min(up, min(upright, upleft));
            }
            prev = cur;
        }

        int ans = INT_MAX;
        for (int j=0; j<n; j++){
            ans = min(ans, cur[j]);
        }

        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        /*
        recursion
        int ans = INT_MAX;
        for (int j=0; j<n; j++){
            ans = min(ans, f1(n-1, j, matrix, n));
        } 
        return ans;
        */

        /*
        memoization
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for (int j=0; j<n; j++){
            ans = min(ans, f2(n-1, j, matrix, n, dp));
        } 
        return ans;
        */

        // tabulation
        // return f3(matrix);

        // space optimization
        return f4(matrix);
    }
};