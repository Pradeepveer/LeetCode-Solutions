#include<bits/stdc++.h>
using namespace std;


void findcomb(int indx, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int n){
    if (indx == n){
        if (target == 0) ans.push_back(ds);\
        return;
    }

    // pick
    if (candidates[indx] <= target){
        ds.push_back(candidates[indx]);
        findcomb(indx, target - candidates[indx], candidates, ans, ds, n);
        ds.pop_back();
    }
    findcomb(indx+1, target, candidates, ans, ds, n);
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    int n = candidates.size();
    findcomb(0, target, candidates, ans, ds, n);
    return ans;    
}