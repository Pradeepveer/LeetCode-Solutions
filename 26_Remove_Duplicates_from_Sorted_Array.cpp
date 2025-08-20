#include<bits/stdc++.h>
using namespace std;


// 1 2 2 3 3 4 5 6 6 7
// 11ms
int removeDuplicates(vector<int>& nums) {
    int l = nums.size();
    if (l == 1){return 1;}        

    int ans = 1;

    int i = 0, j = 1;
    while(i<l && j<l){
        if (nums[i] == nums[j]){
            j++;
        }
        else{
            i++;
            nums[i] = nums[j];
            j++;
            ans++;
        }
    }
    return ans;
}


// 0ms
int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1)    return 1;
        int startIdx = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                startIdx++;
                nums[startIdx] = nums[i];
            }  
        }
        return startIdx+1;
    }