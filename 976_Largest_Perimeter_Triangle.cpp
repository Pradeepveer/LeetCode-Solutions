#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        while(true){
            int n = nums.size();
            if (n < 3) break;

            if (nums[n-1] < nums[n-2] + nums[n-3]){
                return nums[n-1] + nums[n-2] + nums[n-3];
            }
            else nums.pop_back();
        }

        return 0;
    }
};
