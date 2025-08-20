#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkPalindrome(int i, int j, string& s){
        while (i < j){
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    // recursion
    int f1(int i, int n, string& s){
        if (i == n) return 0;
        string temp = "";
        int mini = INT_MAX;

        for (int j=i; j<n; j++){
            if (checkPalindrome(i, j, s)){
                int ways = 1 + f1(j+1, n, s);
                mini = min(mini, ways);
            }
        }
        return mini;
    }

    // memoization
    int f2(int i, int n, string& s, vector<int>& dp){
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for (int j=i; j<n; j++){
            if (checkPalindrome(i, j, s)){
                int ways = 1 + f2(j+1, n, s, dp);
                mini = min(mini, ways);
            }
        }
        return dp[i] = mini;
    }

    // tabulation
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        for (int i=n-1; i>=0; i--){
            int mini = INT_MAX;
            for (int j=n-1; j>=i; j--){
                if (checkPalindrome(i, j, s)){
                    int ways = 1 + dp[j+1];
                    mini = min(mini, ways);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1;
    }

    int minCut(string s) {
        int n = s.size();
        
        // recursion
        // return f1(0, n, s) - 1;

        // memoization
        vector<int> dp(n, -1);
        return f2(0, n, s, dp) - 1;
    }
};