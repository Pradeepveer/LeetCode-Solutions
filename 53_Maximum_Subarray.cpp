#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxsum = nums[0];
    int cursum = 0;
    for (int i=0; i<nums.size(); i++){
        if (cursum<0){
            cursum = 0;
        }
        cursum += nums[i];
        if(cursum > maxsum){
            maxsum = cursum;
        }

    }
    return maxsum;
}
