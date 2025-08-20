#include<bits/stdc++.h>
using namespace std;



class DisjointSet {
    vector<int> rank, size, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // finding ultimate parent
    int findparent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
            parent[pv] = pu;
        else if (rank[pu] > rank[pv])
            parent[pu] = pv;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }

        return;
    }

    void unionbysize(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        return;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;

        for (auto it : stones) {
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }

        unordered_map<int, int> stonenodes;
        DisjointSet ds(maxrow + maxcol + 1);

        for (auto it : stones) {
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.unionbysize(nodecol, noderow);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;
        }

        int cnt = 0;

        for (auto it : stonenodes) {
            if (ds.findparent(it.first) == it.first)
                cnt++;
        }

        return stones.size() - cnt;
    }
};