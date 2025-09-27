#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;

        for (int i=0; i<n-2; i++){
            for (int j=i+1; j<n-1; j++){
                int sum = nums[i] + nums[j];
                int low = j+1;
                int high = n-1;

                while(low <= high){
                    int mid = (low + high)/2;
                    if (nums[mid] < sum) low = mid + 1;
                    else high = mid - 1;
                }

                cnt += low - j - 1;
            }
        }

        return cnt;
    }
};