#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool check(string s){
        int len = s.size();
        if (len == 0 || len == 1) return true;
        for (int i=0; i<=len/2; i++){
            if (s[i] != s[len-1-i]) return false;
        }
        return true;
    }

    // recursion
    int f1(int ind, string str, string& s){
        if (ind < 0){
            if (check(str)) return str.size();
            return 0;
        }

        int notpick = f1(ind-1, str, s);
        int pick = f1(ind-1, s[ind]+str, s);

        return max(pick, notpick);
    }

    // memoization
    int f2(int ind, string str, string& s, map<pair<int, string>, int>& mpp){
        if (ind < 0){
            if (check(str)) return str.size();
            return 0;
        }

        if (mpp.count({ind, str}) != 0) return mpp[{ind, str}];

        int notpick = f2(ind-1, str, s, mpp);
        int pick = f2(ind-1, s[ind]+str, s, mpp);

        return mpp[{ind, str}] = max(pick, notpick);
    }

    // using longest common subsequence
    // space optimiztion
    int f3(string text1, string text2){
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);

        for (int j=0; j<=m; j++) prev[j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]); 
            }
            prev = cur;
        }

        return prev[m];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string str = "";
    
        // recursion
        // return f1(n-1, str, s);

        // memoization
        map<pair<int, string>, int> mpp;
        return f2(n-1, str, s, mpp);

        // using longest common subsequence
        string s2 = s;
        reverse(s.begin(), s.end());
        return f3(s, s2);
    }
};