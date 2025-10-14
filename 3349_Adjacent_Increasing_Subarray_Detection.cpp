#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev = 1;
        int cur = 1;
        int n = nums.size();
        for (int i=1; i<n; i++){
            if (prev >= k && cur >= k || cur >= 2*k) return true;
            if (nums[i] > nums[i-1]) cur++;
            else{
                prev = cur;
                cur = 1;
            }
        }
        if (prev >= k && cur >= k || cur >= 2*k) return true;
        return false;
    }
};