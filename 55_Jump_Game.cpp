#include<bits/stdc++.h>
using namespace std;


bool canJump(vector<int>& nums) {
    int maxindx = 0;
    for (int i=0; i<nums.size(); i++){
        if (i > maxindx) return false;
        maxindx = max(maxindx, i + nums[i]);
        if (maxindx >= nums.size()) return true;
    }        
    return true;
}
