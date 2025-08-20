#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = 0;
    // move all the nonzero elements advance
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[j++], nums[i]);
        }
    }
    return;
}