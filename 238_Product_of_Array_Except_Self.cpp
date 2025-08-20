#include<bits/stdc++.h>
using namespace std;

//28ms
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 0);
    int count_0 = 0;
    int indx0 = -1;
    int allprod = 1;
    for (int i=0; i<nums.size(); i++){
        if (nums[i] == 0){
            count_0++;
            indx0 = i;
            if (count_0 > 1){
                return ans;
            }
        }
        else {
            allprod *= nums[i];
        }
    }        

    if (count_0 == 1){
        ans[indx0] = allprod;
        return ans;
    }

    for (int i=0; i<nums.size(); i++){
        ans[i] = allprod / nums[i];
    }

    return ans;
}

