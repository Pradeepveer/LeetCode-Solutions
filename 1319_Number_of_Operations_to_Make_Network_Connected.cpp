#include<bits/stdc++.h>
using namespace std;


class DisjointSet{

public :
    
    vector<int> rank, size, parent;

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntextra = 0;
        
        for (int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if (ds.findparent(u) == ds.findparent(v)){
                cntextra++;
            }

            else {
                ds.unionbysize(u, v);
            }
        }

        int cntcomp = 0;

        for (int i=0; i<n; i++){
            if (ds.parent[i] == i) cntcomp++;
        }

        int ans = cntcomp - 1;
        if (cntextra >= ans) return ans;
        return -1;
    }
};