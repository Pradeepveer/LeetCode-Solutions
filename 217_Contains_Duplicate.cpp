#include<bits/stdc++.h>
using namespace std;


bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> map;
    for (int i=0; i<nums.size(); i++){
        if (map.count(nums[i])){
            return true;
        }
        map[nums[i]] = 1;
    }        
    return false;
}
