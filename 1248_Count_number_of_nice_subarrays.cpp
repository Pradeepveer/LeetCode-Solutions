#include<bits/stdc++.h>
using namespace std;


int oddcntlessorequal(vector<int>& nums, int k){
    if (k < 0) return 0;
    int l=0, r=0, oddcnt=0, cnt=0;

    while (r < nums.size()){
        oddcnt += (nums[r] % 2 == 1);
        while(oddcnt > k){
            oddcnt -= (nums[l] % 2 == 1);
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
}


int numberOfSubarrays(vector<int>& nums, int k) {
    return oddcntlessorequal(nums, k) - oddcntlessorequal(nums, k-1);
}