#include<bits/stdc++.h>
using namespace std;

double minimumAverage(vector<int>& nums) {
    double temp;
    vector<double> v;
    for (int i=0; i<nums.size(); i++){
        v.push_back(nums[i]);
    }
    sort(v.begin(), v.end());
    double minaverage = (v[0] + v[nums.size() - 1])/2;
    for (int i=0; i<v.size()/2; i++){
        temp = (v[i] + v[nums.size() -1 -i])/2;
        minaverage = min(minaverage, temp);
    }
    return minaverage;
}