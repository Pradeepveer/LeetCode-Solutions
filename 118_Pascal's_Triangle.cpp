#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i=0; i<numRows; i++){
        vector<int> v;
        v.push_back(1);
        for (int j=1; j<i; j++){
            int a = ans[i-1][j-1] + ans[i-1][j];
            v.push_back(a);
        }
        if (i>0){
            v.push_back(1);
        }
        ans.push_back(v);
    }
    return ans;
}