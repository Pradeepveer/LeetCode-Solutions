#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int i, int j, string s, string t){
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (s[i] == t[j]) return f1(i-1, j, s, t) + f1(i-1, j-1, s, t);
        else return f1(i-1, j, s, t);
    }

    // memoization
    int f2(int i, int j, string s, string t, vector<vector<int>>& dp){
        if (j < 0) return 1;
        if (i < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) return dp[i][j] = f2(i-1, j, s, t, dp) + f2(i-1, j-1, s, t, dp);
        else return dp[i][j] = f2(i-1, j, s, t, dp);
    }

    // tabulation
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        for (int i=0; i<=n; i++) dp[i][0] = 1;
        // no need since already 0 
        // for (int j=1; j<=m; j++) dp[0][j] = 0;

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }

    // space optimization
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<double> prev(m+1, 0), cur(m+1, 0);
        prev[0] = 1;
        cur[0] = 1;

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (s[i-1] == t[j-1]) cur[j] = prev[j] + prev[j-1];
                else cur[j] = prev[j];
            }
            prev = cur;
        }
        return (int)cur[m];
    }

    // space optimization single array
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<double> cur(m+1, 0);
        cur[0] = 1;

        for (int i=1; i<=n; i++){
            for (int j=m; j>m; j--){
                if (s[i-1] == t[j-1]) cur[j] = cur[j] + cur[j-1];
                else cur[j] = cur[j];
            }
        }
        return (int)cur[m];
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        // recursion
        // return f1(n-1, m-1, s, t);

        // memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f2(n-1, m-1, s, t, dp);
    }
};