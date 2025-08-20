#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        long long len;
        for (int i=0; i<n; i++){
            if (nums[i] == 0){
                len = 0;
                while(i < n && nums[i] == 0){
                    i++;
                    len++;
                }
                ans = ans + (len+1)*len/2;
            }
        }
        return ans;
    }
};