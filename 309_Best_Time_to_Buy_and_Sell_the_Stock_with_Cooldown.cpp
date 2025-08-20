#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int f1(int ind, int buy, vector<int>& prices){
        if (ind >= prices.size()){
            return 0;
        }

        int profit = 0;
        if (buy){
            int take = -prices[ind] + f1(ind+1, 0, prices);
            int nottake = f1(ind+1, 1, prices);
            profit = max(take, nottake);
        }

        else {
            int sell = prices[ind] + f1(ind+2, 1, prices);
            int notsell = f1(ind+1, 0, prices);
            profit = max(sell, notsell);
        }
        return profit;
    }

    // memoization
    int f2(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if (ind >= prices.size()){
            return 0;
        }

        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = INT_MIN;
        if (buy){
            int take = -prices[ind] + f2(ind+1, 0, prices, dp);
            int nottake = f2(ind+1, 1, prices,dp);
            profit = max(take, nottake);
        }

        else {
            int sell = prices[ind] + f2(ind+2, 1, prices, dp);
            int notsell = f2(ind+1, 0, prices, dp);
            profit = max(sell, notsell);
        }
        return dp[ind][buy] = profit;
    }

    // tabulation
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        dp[n][0] = dp[n+1][0] = 0;
        dp[n][1] = dp[n+1][0] = 0;

        for (int i=n-1; i>=0; i--){
            for (int j=0; j<2; j++){
                int profit = INT_MIN;
                if(j==1){
                    int take = -prices[i] + dp[i+1][0];
                    int nottake = dp[i+1][1];
                    profit = max(take, nottake);
                }
                else{
                    int sell = prices[i] + dp[i+2][1];
                    int notsell = dp[i+1][0];
                    profit = max(notsell, sell);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }

    // space optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2, 0), next(2, 0), next2(2, 0);

        for (int i=n-1; i>=0; i--){
            for (int j=0; j<2; j++){
                int profit = INT_MIN;
                if(j==1){
                    int take = -prices[i] + next[0];
                    int nottake = next[1];
                    profit = max(take, nottake);
                }
                else{
                    int sell = prices[i] + next2[1];
                    int notsell = next[0];
                    profit = max(notsell, sell);
                }
                cur[j] = profit;
            }
            next2 = next;
            next = cur;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {    
        int n = prices.size();

        // recursion
        // return f1(0, 1, prices);        

        // memoization
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f2(0, 1, prices, dp);
    }
};