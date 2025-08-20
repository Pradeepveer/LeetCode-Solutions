#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    // recursion
    int f(int ind, vector<int>& nums){
        if (ind == 0) return nums[0];
        if (ind < 0) return 0;

        int pick = nums[ind] + f(ind-2, nums);
        int notpick = 0 + f(ind-1, nums);

        return max(pick, notpick);
    }

    // memoization
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if (ind == 0) return nums[0];
        if (ind < 0) return 0;
        if (dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + f(ind-2, nums, dp);
        int notpick = 0 + f(ind-1, nums, dp);

        return max(pick, notpick);
    }

    // tabulation
    int f(vector<int>& nums, vector<int>& dp, int n){
        dp[0] = nums[0];
        int pick = 0;
        int notpick = 0;

        for (int i=1; i<n; i++){
            pick = nums[i];
            if (i>1) pick += dp[i-2];
            
            notpick = dp[i-1];
            
            dp[i] = max(pick, notpick);
        }
        return dp[n-1];
    }

    // spzce optimiaztion
    int f(vector<int>& nums){
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        int cur = 0;
        
        for (int i=1; i<n; i++){
            int pick = nums[i];
            if (i>1) pick += prev2;
            int notpick = 0 + prev;
            cur = max(pick, notpick);

            prev2 = prev;
            prev = cur;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // memoization
        // vector<int> dp(n+1, -1);
        // return f(n-1, nums, dp);

        // tabulation
        // vector<int> dp(n);
        // return f(nums, dp, n);  

        // space optimization
        return f(nums);
    }
};