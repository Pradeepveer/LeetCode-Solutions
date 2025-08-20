#include<bits/stdc++.h>
using namespace std;

// 25463    2455674     132
// 25634    2455746     213


void nextPermutation(vector<int>& nums) {
    int l = nums.size();
    int index = -1;
    for (int i=l-2; i>=0; i--){
        if (nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }
    if (index == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i=l-1; i>index; i--){
        if (nums[i] > nums[index]){
            swap (nums[i], nums[index]);
            break;
        }
    }

    reverse(nums.begin()+index+1, nums.end());
    return;
}

// strivers
void nextPermutation(vector<int>& nums){
    int n = nums.size(); // size of the array.
    int ind = -1; // break point
    
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        // reverse the whole array:
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = n - 1; i > ind; i--) {
        if (nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() + ind + 1, nums.end());

    return;
}