#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }

    bool check(string& s1, string& s2){
        if (s1.size() + 1 != s2.size()) return false;
        int i = 0, j = 0;

        while (j < s2.size()){
            if (s1[i] == s2[j]){
                i++; j++;
            }
            else j++;
        }

        if (i == s1.size() && j == s2.size()) return true;
        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastind = 0;
        sort(words.begin(), words.end(), comp);

        for (int i=0; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                if (check(words[prev], words[i]) && 1+dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if (dp[i] > maxi){
                maxi = dp[i];
                lastind = i;
            }
        }
        
        return maxi;        
    }
};  