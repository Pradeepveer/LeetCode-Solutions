#include<bits/stdc++.h>
using namespace std;


void findcomb(int indx, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int n){
    if (target == 0){
        ans.push_back(ds);
        return;
    } 

    for (int i=indx; i<n; i++){
        if (i>indx && candidates[i] == candidates[i-1]) continue;
        if (candidates[i] > target) break;

        ds.push_back(candidates[i]);
        findcomb(i+1, target - candidates[i], candidates, ans, ds, n);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> ds;
    vector<vector<int>> ans;
    int n = candidates.size();

    findcomb(0, target, candidates, ans, ds, n);
    return ans;
}