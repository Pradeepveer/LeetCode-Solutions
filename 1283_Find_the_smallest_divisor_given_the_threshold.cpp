#include<bits/stdc++.h>
using namespace std;

int sum(vector<int>& nums, int divisor){
    int s = 0;
    for (int i=0; i<nums.size(); i++){
        s += ceil((double)nums[i]/(double)divisor);
    }
    return s;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    while(low <= high){
        int mid = (low+high)/2;
        int s = sum(nums, mid);
        if (s <= threshold) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}   