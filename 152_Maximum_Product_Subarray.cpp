#include<bits/stdc++.h>
using namespace std;

// 1 2 4 3  0 -1 3 3 =2 -5 0 3 6
int maxProduct(vector<int>& nums) {
    int pf = 1;
    int sf = 1;
    int n = nums.size();
    int ans = INT_MIN;

    for (int i=0; i<n; i++){
        if (pf == 0){pf = 1;}
        if (sf == 0){sf = 1;}
        pf *= nums[i];
        sf *= nums[n-1-i];
        ans = max(ans, max(pf, sf));
    }
    return ans;
}
