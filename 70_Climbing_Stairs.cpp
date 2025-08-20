#include<bits/stdc++.h>
using namespace std;


class Solution {
    int prev = 1;
    int prev2 = 0;
    vector<int> dp;

public:
    // recursion
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 0) return 1;

        int jump1 = climbStairs(n-1);
        int jump2 = climbStairs(n-2);
        
        return jump1 + jump2;
    }

    // tabulation
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    // space optimization
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 0) return 1;
        int prev1 = 1;
        int prev2 = 1;
        int cur;

        for (int i=2; i<=n; i++){
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return cur;        
    }
};