#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
    vector<int> rank, size, parent;

public :
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i=0; i<=n; i++){
            parent[i] = i; 
        }
    }

    // finding ultimate parent
    int findparent(int node){
        if (node == parent[node]) return node;
        return parent[node] = findparent(parent[node]);
    }

    void unionbyrank(int u, int v){
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv) return;
        if (rank[pu] < rank[pv]) parent[pv] = pu;
        else if (rank[pu] > rank[pv]) parent[pu] = pv;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }

        return;
    }

    void unionbysize(int u, int v){
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv) return;
        if (size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        return;
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp;
        
        for (int i=0; i<n; i++){
            for (int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end()) {
                    mpp[mail] = i;
                }
                else ds.unionbysize(i, mpp[mail]);
            }
        }

        vector<vector<string>> mergedmail(n);
        
        for(auto it : mpp){ 
            string mail = it.first;
            int node = ds.findparent(it.second);
            mergedmail[node].push_back(mail);

        }

        vector<vector<string>> ans;

        for (int i=0; i<n; i++){
            if (mergedmail[i].size() == 0) continue;
            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};