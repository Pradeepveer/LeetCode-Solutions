#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(const int i:nums){
        ans = ans^i;
    }        
    return ans;
}