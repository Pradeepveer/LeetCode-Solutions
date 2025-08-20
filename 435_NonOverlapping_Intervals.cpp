#include<bits/stdc++.h>
using namespace std;


bool static comp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    int cnt = 1;
    int lastendtime = intervals[0][1];
    for (int i=1; i<intervals.size(); i++){
        if (intervals[i][0] >= lastendtime){
            cnt++;
            lastendtime = intervals[i][1];
        }
    }
    return intervals.size() - cnt;
}
