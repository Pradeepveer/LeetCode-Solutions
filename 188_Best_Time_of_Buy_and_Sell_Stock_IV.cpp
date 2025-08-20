#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int ind, int buy, int transactions, vector<int>& prices){
        if (ind == prices.size() || transactions == 0) return 0;

        int profit = 0;
        if (buy){
            int take = -prices[ind] + f1(ind+1, 0, transactions, prices);
            int nottake = f1(ind+1, 1, transactions, prices);
            profit = max(take, nottake);
        }

        else {
            int sell = prices[ind] + f1(ind+1, 1, transactions - 1, prices);
            int notsell = f1(ind+1, 0, transactions, prices);
            profit = max(sell, notsell);
        }
        return profit;
    }   

    // memoization
    int f2(int ind, int buy, int transactions, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if (ind == prices.size() || transactions == 0) return 0;
        if (dp[ind][buy][transactions] != -1) return dp[ind][buy][transactions];

        int profit = 0;
        if (buy){
            int take = -prices[ind] + f2(ind+1, 0, transactions, prices, dp);
            int nottake = f2(ind+1, 1, transactions, prices, dp);
            profit = max(take, nottake);
        }

        else {
            int sell = prices[ind] + f2(ind+1, 1, transactions - 1, prices, dp);
            int notsell = f2(ind+1, 0, transactions, prices, dp);
            profit = max(sell, notsell);
        }
        return dp[ind][buy][transactions] = profit;
    }

    // tabulation
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // for base case initial values are already zero so no need to write base case again

        for (int i=n-1; i>=0; i--){
            for (int j=0; j<2; j++){
                for(int trns=1; trns<=k; trns++){
                    int profit = 0;
                    if(j==1){
                        int take = -prices[i] + dp[i+1][0][trns];
                        int nottake = dp[i+1][1][trns];
                        profit = max(take, nottake);
                    }
                    else{
                        int sell = prices[i] + dp[i+1][1][trns-1];
                        int notsell = dp[i+1][0][trns];
                        profit = max(notsell, sell);
                    }
                    dp[i][j][trns] = profit;
                }
            }
        }
        return dp[0][1][k];
    }

    // space optimization
    int maxProfit(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(k+1, 0)), cur(2, vector<int>(k+1, 0));
        // for base case initial values are already zero so no need to write base case again

        for (int i=n-1; i>=0; i--){
            for (int j=0; j<2; j++){
                for(int trns=1; trns<=k; trns++){
                    int profit = 0;
                    if(j==1){
                        int take = -prices[i] + next[0][trns];
                        int nottake = next[1][trns];
                        profit = max(take, nottake);
                    }
                    else{
                        int sell = prices[i] + next[1][trns-1];
                        int notsell = next[0][trns];
                        profit = max(notsell, sell);
                    }
                    cur[j][trns] = profit;
                }
                next = cur;
            }
        }
        return next[1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // recursion
        // return f1(0, 1, k, prices);

        // memoization
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f2(0, 1, k, prices, dp);
    }
};