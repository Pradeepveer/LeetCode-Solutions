#include<bits/stdc++.h>
using namespace std;


void findsum(int indx, vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, int n){
    ans.push_back(ds);

    for (int i=indx; i<n; i++){
        if (i>indx && nums[i] == nums[i-1]) continue;

        ds.push_back(nums[i]);
        findsum(i+1, nums, ans, ds, n);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findsum(0, nums, ans, ds, n);
    return ans;
}