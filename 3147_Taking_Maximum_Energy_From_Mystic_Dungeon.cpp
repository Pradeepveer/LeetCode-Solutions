#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> arr(k, 0);
        int maxi = INT_MIN;
        for (int i=energy.size()-1; i>=0; i--){
            int ind = i%k;
            arr[ind] += energy[i];
            maxi = max(maxi, arr[ind]);
        }
        
        return maxi;
    }
};