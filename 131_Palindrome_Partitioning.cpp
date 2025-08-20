#include<bits/stdc++.h>
using namespace std;


bool ispalindrome(string s, int start, int end){
    while(start<=end){
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void func(int indx, string s, vector<string>& ds, vector<vector<string>>& ans, int n){
    if (indx == n){
        ans.push_back(ds);
        return;
    }

    for (int i=indx; i<n; i++){
        if (ispalindrome(s, indx, i)){
            ds.push_back(s.substr(indx, i-indx+1));
            func(i+1, s, ds, ans, n);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> ds;
    int n = s.size();

    func(0, s, ds, ans, n);
    return ans;
}