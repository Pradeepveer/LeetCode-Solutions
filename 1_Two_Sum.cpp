#include<bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int>nums, int target) {
    int l = nums.size();
    for(int i = 0; i != l; i++){
        int a = nums[i];
        int b = target - a;
        for (int j = i+1; j!=l; j++){
            if (nums[j] == b){
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                return v;
            }
        }
            
    }
    return {};
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.count(complement)) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}



int main(){
    vector<int> nums;   
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    //    cout<<twoSum(nums, 9)<<endl;
    return 0;
}