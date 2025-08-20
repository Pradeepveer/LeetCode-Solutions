#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // recursion
    int f1(int ind, int n, vector<int>& arr, int k){
        if (ind == n) return 0;

        int maxans = INT_MIN;
        int l = 0, maxi = INT_MIN;
        for (int j=ind; j<min(n, ind+k); j++){
            l++;
            maxi = max(maxi, arr[j]);
            int sum = l*maxi + f1(j+1, n, arr, k);
            maxans = max(maxans, sum);
        }
        return maxans;
    }

    // memoization
    int f2(int ind, int n, vector<int>& arr, int k, vector<int>& dp){
        if (ind == n) return 0;
        if (dp[ind] != -1) return dp[ind];
        int maxans = INT_MIN;
        int l = 0, maxi = INT_MIN;
        for (int j=ind; j<min(n, ind+k); j++){
            l++;
            maxi = max(maxi, arr[j]);
            int sum = l*maxi + f2(j+1, n, arr, k, dp);
            maxans = max(maxans, sum);
        }
        return dp[ind] = maxans;
    }

    // tabulation
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for (int ind=n-1; ind>=0; ind--){
            int maxans = INT_MIN;
            int l = 0, maxi = INT_MIN;
            for (int j=ind; j<min(n, ind+k); j++){
                l++;
                maxi = max(maxi, arr[j]);
                int sum = l*maxi + dp[j+1];
                maxans = max(maxans, sum);
            }
            dp[ind] = maxans;
        }

        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // recursion
        // return f1(0, n, arr, k);

        // memoization
        vector<int> dp(n+1, -1);
        return f2(0, n, arr, k, dp);
    }
};