#include<bits/stdc++.h>
using namespace std;

int fn = 0;
int fib(int n) {
    if (n == 0){
        fn = 0;
    }        
    else if(n==1){
        fn = 1;
    }

    else{
        fn = fib(n-2) + fib(n-1);
    }

    return fn;
}


// 0ms solution
// recursion + memoization
int solve1(int n, vector<int> &dp){
    if (n == 0 || n == 1)
        return n;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = solve1(n-1, dp) + solve1(n-2, dp);
}

// bottom up
int solve2(int n){
    if (n == 0 || n == 1)
        return n;
    vector<int> dp(n + 1, -1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// bottom up + space optimization
int solve3(int n){
    if (n == 0 || n == 1)
        return n;
    int prev1 = 0, prev2 = 1;
    for (int i = 2; i <= n; i++){
        int temp = prev1 + prev2;
        prev1 = prev2;
        prev2 = temp;
    }
    return prev2;
}

int fib(int n) {
    return solve3(n);
}