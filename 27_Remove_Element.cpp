#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r = nums.size() - 1;
        int l = 0;
        int valcnt = 0;
        while(l <= r){
            if (nums[l] == val){
                swap(nums[l], nums[r]);
                r--;
            }
            else l++;
        }
        nums.resize(l);
        return l;
    }
};
