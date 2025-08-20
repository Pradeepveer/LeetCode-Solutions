#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int ind, int amount, vector<int>& coins){
        if (ind == 0){
            if (amount % coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }

        int nottake = f1(ind-1, amount, coins);
        int take = INT_MAX;
        if (amount >= coins[ind]) take = 1 + f1(ind, amount - coins[ind], coins);

        return min(take, nottake);
    }

    // memoization
    int f2(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if (ind == 0){
            if (amount % coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }
        if (dp[ind][amount] != -1) return dp[ind][amount];

        int nottake = f2(ind-1, amount, coins, dp);
        int take = INT_MAX;
        if (amount >= coins[ind]) take = 1 + f2(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = min(take, nottake);
    }

    // tabulation
    int f3(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        for (int i=0; i<=amount; i++){
            if (i % coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }

        for (int ind=1; ind<n; ind++){
            for (int target=0; target<=amount; target++){
                int nottake = dp[ind-1][target];
                int take = INT_MAX;
                if (target >= coins[ind]) take = 1 + dp[ind][target-coins[ind]];

                dp[ind][target] = min(take, nottake);
            }
        }
        
        if(dp[n-1][amount] == 1e9) return -1;   
        return dp[n-1][amount];
    }

    // space optimization
    int f4(vector<int>& coins, int amount){
        int n = coins.size();
        vector<int> prev(amount+1, 0);
        vector<int> cur(amount+1, 0);

        for (int i=0; i<=amount; i++){
            if (i % coins[0] == 0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }

        for (int ind=1; ind<n; ind++){
            for (int target=0; target<=amount; target++){
                int nottake = prev[target];
                int take = INT_MAX;
                if (target >= coins[ind]) take = 1 + cur[target-coins[ind]];

                cur[target] = min(take, nottake);
            }
            prev = cur;
        }
        
        if(prev[amount] == 1e9) return -1;   
        return prev[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // recursion
        // int ans = f1(n-1, amount, coins);
        // if (ans == 1e9) return -1;
        // return ans;

        // memoization
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f2(n-1, amount, coins, dp);
        if (ans == 1e9) return -1;
        return ans;
    }
};