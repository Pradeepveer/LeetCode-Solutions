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