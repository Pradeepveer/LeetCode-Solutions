#include<bits/stdc++.h>
using namespace std;


int subarrsumlessorequal(vector<int>& nums, int goal){
    if (goal < 0) return 0;
    int l=0, r=0, sum=0, cnt=0;

    while (r < nums.size()){
        sum += nums[r];
        while(sum > goal){
            sum -= nums[l];
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
}


int numSubarraysWithSum(vector<int>& nums, int goal) {
    return subarrsumlessorequal(nums, goal) - subarrsumlessorequal(nums, goal-1);
}