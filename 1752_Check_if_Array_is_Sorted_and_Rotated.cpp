#include<bits/stdc++.h>
using namespace std;


bool check(vector<int>& nums) {
    int ind = 0;
    int l = nums.size();

    if (l == 1){
        return true;
    }

    for (int i=1; i<l; i++){
        if (nums[i] < nums[i-1]){
            ind = l-i;
            break;
        }
    }

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+ind);
    reverse(nums.begin()+ind, nums.end());

    for (int i=0; i<l-1; i++){
        if (nums[i] > nums[i+1]){
            return false;
            break;
        }
    }
    return true;
}