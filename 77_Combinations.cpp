#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(vector<int>& arr, vector<vector<int>>& ans, vector<int>& temp, int n, int k, int ind){
        if (temp.size() == k){
            ans.push_back(temp);
            return;
        }

        else if (ind == n) return;

        // pick
        temp.push_back(arr[ind]);
        dfs(arr, ans, temp, n, k, ind+1);
        temp.pop_back();

        // not pick
        dfs(arr, ans, temp, n, k, ind+1);
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> arr(n);
        for (int i=1; i<=n; i++){
            arr[i-1] = i;
        }        

        if (n == k) return {arr};
        if (k == 0) return {};
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(arr, ans, temp, n, k, 0);
        return ans;
    }
};

class Solution {
public:
    void dfs1(vector<vector<int>>& ans, vector<int>& temp, int n, int k, int start){
        if (temp.size() == k){
            ans.push_back(temp);
            return;
        }

        for (int i=start; i<=n; i++){
            temp.push_back(i);
            dfs1(ans, temp, n, k, i+1); 
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {  
        vector<vector<int>> ans;
        vector<int> temp;

        dfs1(ans, temp, n, k, 1);
        return ans;
    }
};