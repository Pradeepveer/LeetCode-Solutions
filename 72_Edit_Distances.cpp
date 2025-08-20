#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    // recursion
    int f1(int i, int j, string word1, string word2){
        if (j < 0) return i+1;  // extra chars at start of word1 to delete
        if (i < 0) return j+1;  // extra chars need to insert to make word2

        if (word1[i] == word2[j]) return f1(i-1, j-1, word1, word2);
        int insert = 1 + f1(i, j-1, word1, word2);
        int del = 1 + f1(i-1, j, word1, word2);
        int replace = 1 + f1(i-1, j-1, word1, word2);
        
        return min(insert, min(del, replace));
    }

    // memoization
    int f2(int i, int j, string word1, string word2, vector<vector<int>>& dp){
        if (j < 0) return i+1;  // extra chars at start of word1 to delete
        if (i < 0) return j+1;  // extra chars need to insert to make word2

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) return f2(i-1, j-1, word1, word2, dp);
        int insert = 1 + f2(i, j-1, word1, word2, dp);
        int del = 1 + f2(i-1, j, word1, word2, dp);
        int replace = 1 + f2(i-1, j-1, word1, word2, dp);
        
        return dp[i][j] = min(insert, min(del, replace));
    }

    // tabulation
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
    
        // index shifting
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i=0; i<=n; i++) dp[i][0] = i;
        for (int j=1; j<=m; j++) dp[0][j] = j;

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = 1 + dp[i][j-1];
                    int del = 1+ dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];
                    dp[i][j] = min(insert, min(del, replace));
                }
            }
        }
        return dp[n][m];
    }

    // space optimization
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
    
        // index shifting
        vector<int> prev(m+1, 0);
        for (int j=0; j<=m; j++) prev[j] = j;

        for (int i=1; i<=n; i++){
            vector<int> cur(m+1, 0);
            cur[0] = i;
            for (int j=1; j<=m; j++){
                if (word1[i-1] == word2[j-1]) cur[j] = prev[j-1];
                else{
                    int insert = 1 + cur[j-1];
                    int del = 1+ prev[j];
                    int replace = 1 + prev[j-1];
                    cur[j] = min(insert, min(del, replace));
                }
            }
            prev = cur;
        }
        return prev[m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // recursion      
        // return f1(n-1, m-1, word1, word2);

        // memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f2(n-1, m-1, word1, word2, dp);
    }
};