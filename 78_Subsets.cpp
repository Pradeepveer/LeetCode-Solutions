#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    int subsets = 1 << n;

    for (int num=0; num<subsets; num++){
        vector<int> subset;
        for (int i=0; i<n; i++){
            if (num & (1<<i)) subset.push_back(nums[i]);
        }
        ans.push_back(subset);
    }
    return ans;
}