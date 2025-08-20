#include<bits/stdc++.h>
using namespace std;

int dayscount(vector<int>& weights, int cap, int n){
    int days = 0;
    int total = 0;

    for (int i=0; i<n; i++){
        if (total + weights[i] <= cap){
            total += weights[i];
        }
        else {
            days += 1;
            total = weights[i];
        }
    }
    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;        

    for(int i=0; i<n; i++){
        high += weights[i];
    }

    while(low <= high){
        int mid = (low + high)/2;
        int d = dayscount(weights, mid, n);
        if (d < days) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}