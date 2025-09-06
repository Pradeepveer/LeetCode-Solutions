#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    long f1(long i){
        if (i == 1) return 0;

        if (i % 2 == 0) return 1 + f1(i/2);
        else return 1 + min(f1(i+1), f1(i-1));

        return 0;
    }

    // memoization
    long f2(long i, map<long, int>& dp){
        if (i == 1) return 0;
        if (dp.count(i)) return dp[i];

        if (i % 2 == 0) return dp[i] = 1 + f2(i/2, dp);
        else return dp[i] = 1 + min(f2(i+1, dp), f2(i-1, dp));

        return 0;
    }

    int integerReplacement(int n) {
        // recursion
        // return f1(n); 
        
        // memoization
        map<long, int> mp;
        return f2(n, mp);
    }
};