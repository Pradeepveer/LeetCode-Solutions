#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int i, int j, string s1, string s2){
        if (i < 0 || j < 0) return 0;

        if (s1[i] == s2[j]) return 1 + f1(i-1, j-1, s1, s2);
        return max(f1(i-1, j, s1, s2), f1(i, j-1, s1, s2));
    }

    // recursion : index shifting
    int f1a(int i, int j, string s1, string s2){
        if (i == 0 || j == 0) return 0;

        if (s1[i-1] == s2[j-1]) return 1 + f1a(i-1, j-1, s1, s2);
        return max(f1a(i-1, j, s1, s2), f1a(i, j-1, s1, s2));
    }
    // memoization
    int f2(int i, int j, string s1, string s2, vector<vector<int>>& dp){
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) return dp[i][j] = 1 + f2(i-1, j-1, s1, s2, dp);
        return dp[i][j] = max(f2(i-1, j, s1, s2, dp), f2(i, j-1, s1, s2, dp));
    }

    // memoization index shifting
    int f2a(int i, int j, string s1, string s2, vector<vector<int>>& dp){
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i-1] == s2[j-1]) return dp[i][j] = 1 + f2a(i-1, j-1, s1, s2, dp);
        return dp[i][j] = max(f2a(i-1, j, s1, s2, dp), f2a(i, j-1, s1, s2, dp));
    }

    // tabulation after index shifting
    int f3(string text1, string text2){
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i=0; i<=n; i++) dp[i][0] = 0;
        for (int j=0; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }

        return dp[n][m];
    }

    // space optimization after index shifting
    int f4(string text1, string text2){
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);

        for (int j=0; j<=m; j++) prev[j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]); 
            }
            prev = cur;
        }

        return prev[m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // recursion
        // return f1(n-1, m-1, text1, text2);

        // memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f2(n-1, m-1, text1, text2, dp);
    }
};