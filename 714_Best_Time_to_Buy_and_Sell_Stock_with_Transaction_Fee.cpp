#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int f1(int ind, int buy, vector<int>& prices, int fee){
        if (ind == prices.size()){
            return 0;
        }

        int profit = INT_MIN;
        if (buy){
            int take = -fee -prices[ind] + f1(ind+1, 0, prices, fee);
            int nottake = f1(ind+1, 1, prices, fee);
            profit = max(take, nottake);
        }

        else {
            int sell = prices[ind] + f1(ind+1, 1, prices, fee);
            int notsell = f1(ind+1, 0, prices, fee);
            profit = max(sell, notsell);
        }
        return profit;
    }

    // memoization
    int f2(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee){
        if (ind == prices.size()){
            return 0;
        }

        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = INT_MIN;
        if (buy){
            int take = -fee -prices[ind] + f2(ind+1, 0, prices, dp, fee);
            int nottake = f2(ind+1, 1, prices, dp, fee);
            profit = max(take, nottake);
        }

        else {
            int sell = prices[ind] + f2(ind+1, 1, prices, dp, fee);
            int notsell = f2(ind+1, 0, prices, dp, fee);
            profit = max(sell, notsell);
        }
        return dp[ind][buy] = profit;
    }

    // tabulation
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int i=n-1; i>=0; i--){
            for (int j=0; j<2; j++){
                int profit = INT_MIN;
                if(j==1){
                    int take = -fee -prices[i] + dp[i+1][0];
                    int nottake = dp[i+1][1];
                    profit = max(take, nottake);
                }
                else{
                    int sell = prices[i] + dp[i+1][1];
                    int notsell = dp[i+1][0];
                    profit = max(notsell, sell);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }

    // space optimization
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> next(2, 0), cur(2, 0);
        next[0] = 0;
        next[1] = 0;

        for (int i=n-1; i>=0; i--){
            for (int j=0; j<2; j++){
                int profit = INT_MIN;
                if(j==1){
                    int take = -fee -prices[i] + next[0];
                    int nottake = next[1];
                    profit = max(take, nottake);
                }
                else{
                    int sell = prices[i] + next[1];
                    int notsell = next[0];
                    profit = max(notsell, sell);
                }
                cur[j] = profit;
            }
            next = cur;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        // recursion
        // return f1(0, 1, prices, fee);

        // memoization
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f2(0, 1, prices, dp, fee);
    }
};