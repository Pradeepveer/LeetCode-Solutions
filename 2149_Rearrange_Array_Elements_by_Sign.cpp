#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int l = nums.size();
    int pi = 0;
    int ni = 1;

    vector<int> ans(l);
    for (int i=0; i<l; i++){
        if (nums[i] > 0){
            ans[pi] = nums[i];
            pi += 2;
        }        

        else {
            ans[ni] = nums[i];
            ni += 2;
        }
    }

    return ans;
}