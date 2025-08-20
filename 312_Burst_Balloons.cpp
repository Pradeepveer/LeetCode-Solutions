#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int i, int j, vector<int>& nums){
        if (i > j) return 0;
        int maxi = 0;
        for (int k=i; k<=j; k++){
            int coins = nums[i-1]*nums[k]*nums[j+1] + f1(i, k-1, nums) + f1(k+1, j, nums);
            maxi = max(maxi, coins);
        }
        return maxi;
    }

    // memoization
    int f2(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int maxi = 0;
        for (int k=i; k<=j; k++){
            int coins = nums[i-1]*nums[k]*nums[j+1] + f2(i, k-1, nums, dp) + f2(k+1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }

    // tabulation
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for (int i=n; i>=1; i--){
            for (int j=1; j<=n; j++){
                int maxi = 0;
                if (i>j) continue;
                for (int k=i; k<=j; k++){
                    int coins = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // recursion
        // return f1(1, n, nums);

        // memoization
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f2(1, n, nums, dp);
    }
};