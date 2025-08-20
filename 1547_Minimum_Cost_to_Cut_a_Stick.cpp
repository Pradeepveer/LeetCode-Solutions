#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    // recursion
    int f1(int i, int j, vector<int>& cuts){
        if (i > j) return 0;
        int mini = 1e9;
        for (int k=i; k<=j; k++){
            int cost = cuts[j+1] - cuts[i-1] + f1(i, k-1, cuts) + f1(k+1, j, cuts);
            mini = min(mini, cost);
        }

        return mini;
    }

    // memoization
    int f2(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for (int k=i; k<=j; k++){
            int cost = cuts[j+1] - cuts[i-1] + f2(i, k-1, cuts, dp) + f2(k+1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }


    // tabulation
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

        for (int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                if (i > j) continue;
                int mini = 1e9;
                for (int k=i; k<=j; k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][c]; 
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        // recursion
        // return f1(1, c, cuts);

        // memoization
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return f2(1, c, cuts, dp);
    }
};