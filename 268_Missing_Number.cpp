#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = n*(n+1)/2;
    int s = 0;
    for (const int i : nums){
        s += i;
    }
    return sum - s;
}


int missingNumber(vector<int>& nums) {
    int xor1 = 0;
    for (int i=0; i<nums.size(); i++){
        xor1 = xor1^nums[i]^(i+1);
    }
    return xor1;
}