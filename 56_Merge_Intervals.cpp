#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i=0; i<intervals.size(); i++){
        if (ans.empty() || intervals[i][0] > ans.back()[1]){
            ans.push_back(intervals[i]);
        }
   
    
        else {
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }        
    }
    return ans;
}

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> ans;
    if (intervals.size() == 0) return ans;

    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];
    for (auto it : intervals){
        if (temp[1] > it[0]){
            temp[1] = max(temp[1], it[1]);
        }

        else{
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
}
