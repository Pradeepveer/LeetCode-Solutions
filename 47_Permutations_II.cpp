#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& vis, vector<int>& temp, int ind, int n){
        if (ind >= n){
            ans.push_back(temp);
            return;
        }

        for (int i=0; i<n; i++){
            if (vis[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;
            vis[i] = 1;
            temp.push_back(nums[i]);
            dfs(nums, ans, vis, temp, ind+1, n);
            vis[i] = 0;
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(nums, ans, vis, temp, 0, n);
        return ans;
    }
};