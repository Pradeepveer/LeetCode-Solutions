#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int ind, int l1, int l2, vector<int>& rods){
        if (ind < 0) return l1 == l2 ? l1 : -1;

        int add1 = f1(ind-1, l1 + rods[ind], l2, rods);
        int add2 = f1(ind-1, l1, l2 + rods[ind], rods);
        int notuse = f1(ind-1, l1, l2, rods);

        return max(add1, max(add2, notuse));
    }

    // memoization
    int f2(int ind, int diff, int sum, vector<int>& rods, vector<vector<int>>& dp){
        if (ind < 0) return diff == 0 ? 0 : -1e9;
        if (dp[ind][diff + sum] != -1) return dp[ind][diff+sum];
        int add1 = rods[ind] + f2(ind-1,  diff + rods[ind], sum, rods, dp);
        int add2 = f2(ind-1, diff - rods[ind], sum, rods, dp);
        int notuse = f2(ind-1, diff, sum, rods, dp);

        return dp[ind][diff+sum] = max(add1, max(add2, notuse));
    }

    // tabulation
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        for (int i=0; i<n; i++) sum += rods[i];
        
        vector<vector<int>> dp(n+1, vector<int> (2*sum+1, -1e9));

        // index shifting by 1
        // base case if ind = 0 and diff != 0
        for (int j=0; j<2*sum+1; j++){
            dp[0][j] = -1e9;
        }
        dp[0][sum] = 0;

        // tabulation   
        int add1, add2, notuse;
        for (int i=1; i<=n; i++){
            for (int diff=-sum; diff<sum; diff++){
                if(diff+rods[i-1] <= sum)  add1 = rods[i-1] + dp[i-1][diff+sum+rods[i-1]];
                if(diff-rods[i-1] >= -sum) add2 = dp[i-1][diff+sum-rods[i-1]];
                int notuse = dp[i-1][diff+sum];
                dp[i][diff+sum] = max(add1, max(add2, notuse));
            }
        }
        return dp[n][sum];
    }

    // space optimization
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        for (int i=0; i<n; i++) sum += rods[i];
        
        vector<int> prev(2*sum+1, -1e9), curr(2*sum+1, -1e9);

        // index shifting by 1
        // base case if ind = 0 and diff != 0
        prev[sum] = 0;

        // tabulation   
        int add1, add2, notuse;
        for (int i=1; i<=n; i++){
            for (int diff=-sum; diff<sum; diff++){
                if(diff+rods[i-1] <= sum)  add1 = rods[i-1] + prev[diff+sum+rods[i-1]];
                if(diff-rods[i-1] >= -sum) add2 = prev[diff+sum-rods[i-1]];
                int notuse = prev[diff+sum];
                curr[diff+sum] = max(add1, max(add2, notuse));
            }
            prev = curr;
        }
        return prev[sum];
    }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        for (int i=0; i<n; i++) sum += rods[i];
        // recursion
        // return f1(n-1, 0, 0, rods);

        // memoization
        vector<vector<int>> dp(n+1, vector<int> (2*sum, -1));
        return f2(n-1, 0, sum, rods, dp);
    }
};