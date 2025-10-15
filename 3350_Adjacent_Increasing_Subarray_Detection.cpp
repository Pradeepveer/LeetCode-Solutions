#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        int curr = 1;

        for (int i=1; i<n; i++){
            if (nums[i] > nums[i-1]){
                curr++;
            }

            else{
                arr.push_back(curr);
                curr = 1;
            }
        }
        arr.push_back(curr);

        int maxi = arr[0];
        int maxcommon = 0;
        for (int i=1; i<arr.size(); i++){
            maxi = max(maxi, arr[i]);
            maxcommon = max(maxcommon, min(arr[i], arr[i-1]));
        }

        return max(maxcommon, maxi/2);
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=1;
        int ans = 0;
        int prev = 0;
        while (j<n){
            if (nums[j] <= nums[j-1]){
                ans = max ({ans, (j-i)/2, min (prev, j-i)});
                prev = j-i;
                i=j;
            }
            j++;
        }
        ans = max ({ans, (j-i)/2, min (prev, j-i)});
        return ans;
    }
};