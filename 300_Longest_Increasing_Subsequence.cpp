#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int ind, int prev, vector<int>& nums){
        if (ind == nums.size()) return 0;

        int nottake = f1(ind+1, prev, nums);
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) take = 1 + f1(ind+1, ind, nums);

        return max(take, nottake);
    }

    // memoization
    int f2(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if (ind == nums.size()) return 0;
        if (dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int nottake = f2(ind+1, prev, nums, dp);
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) take = 1 + f2(ind+1, ind, nums, dp);

        return dp[ind][prev+1] = max(take, nottake);
    }

    // tabulation
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // base case already done on initiallization
        // for (int j=0; j<=n; j++) dp[n][j] = 0;

        for (int ind=n-1; ind>=0; ind--){
            for (int prev=ind-1; prev>=-1; prev--){
                int nottake = dp[ind+1][prev+1];
                int take = 0;
                if (prev == -1 || nums[ind] > nums[prev]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(take, nottake);
            }
        }
        return dp[0][0];
    }

    // space optimization
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> next(n+1, 0), cur(n+1, 0);
        // base case already done on initiallization
        // for (int j=0; j<=n; j++) next[j] = 0;

        for (int ind=n-1; ind>=0; ind--){
            for (int prev=ind-1; prev>=-1; prev--){
                int nottake = next[prev+1];
                int take = 0;
                if (prev == 0 || nums[ind] > nums[prev]){
                    take = 1 + next[ind+1];
                }
                cur[prev+1] = max(take, nottake);
            }
            next = cur;
        }
        return next[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // recursion
        // return f1(0, -1, nums);

        // memoization
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f2(0, -1, nums, dp);
    }

    // another method using 1d array
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i=0; i<n; i++){
            for (int prev=0; prev<i; prev++){
                if (nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1+dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }

    // optimal solution using binary search
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;

        for (int i=1; i<n; i++){
            if (nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;        
    }
};