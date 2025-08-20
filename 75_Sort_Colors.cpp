#include<bits/stdc++.h>
using namespace std;

// Dutch Flag Algorithm
void sortColors(vector<int>& nums) {
    // 0 1 2 : r w b
    int l = nums.size();
    int low = 0, mid = 0, high = l-1;

    while (mid <= high){
        if (nums[mid] == 0){
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1){
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}