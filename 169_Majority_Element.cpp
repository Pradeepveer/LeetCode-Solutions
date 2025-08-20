#include<bits/stdc++.h>
using namespace std;


int majorityElement(vector<int>& nums) {
    int cnt = 0;
    int el;
    int l = nums.size();
    for (int i=0; i<l; i++){
        if (cnt == 0){
            el = nums[i];
            cnt++;
        }
        else if (nums[i] == el){
            cnt++;
        }
        else {
            cnt--;
        }
    }

    return el;
}
