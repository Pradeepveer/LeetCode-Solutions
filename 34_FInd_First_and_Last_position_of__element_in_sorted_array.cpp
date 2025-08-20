#include<bits/stdc++.h>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0;
    int h = n-1;
    int start = -1;
    int end = -1;
    while (l <= h){
        int mid = (l + h)/2;
        if (nums[mid] == target){
            start = mid;
            h = mid - 1;
        }
        else if(nums[mid] > target){
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }        

    l = 0;
    h = n - 1;
    while (l <= h){
        int mid = (l + h)/2;
        if (nums[mid] == target){
            end = mid;
            l = mid + 1;
        }
        else if(nums[mid] > target){
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }    
    return {start, end};
}