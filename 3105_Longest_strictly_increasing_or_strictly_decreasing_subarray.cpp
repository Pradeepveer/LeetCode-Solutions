#include<bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int>& nums) {
    int inc = 1;
    int imax = 1;
    // increasing
    for (int i=1; i<nums.size(); i++){
        if (nums[i] > nums[i-1]){inc++;}
        else {inc = 1;}
        imax = max(imax, inc);
    }

    int dec = 1;
    int dmax = 1;
    // decreasing
    for (int i=1; i<nums.size(); i++){
        if (nums[i] < nums[i-1]){dec++;}
        else {dec = 1;}
        dmax = max(dec, dmax);
    }

    return max(imax, dmax);
}

int longestMonotonicSubarray(vector<int>& nums) {
    int inc = 1;
    int dec = 1;
    int maxi = 1;
    for (int i=1; i<nums.size(); i++){
        if (nums[i] > nums[i-1]){
            inc++;
            dec = 1;
            maxi = max(maxi, inc); 
        }
        else if (nums[i] < nums[i-1]){
            dec++;
            inc = 1;
            maxi = max(maxi, dec);
        }

        else {
            // if nums[i] == nums[i-1]
            inc = 1;
            dec = 1;
        }
    }
    return maxi;
}