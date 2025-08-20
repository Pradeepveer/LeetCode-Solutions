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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        for (int r=0; r<n; r++){
            for (int c=0; c<n; c++){
                if (grid[r][c] == 0) continue;
                for (int i=0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n
                    && grid[nr][nc] == 1){
                        int node = n * r + c;
                        int adjnode = n * nr + nc;
                        ds.unionbysize(node, adjnode);
                    }
                }
            }
        }        

        int mx = 0;

        for (int r=0; r<n; r++){
            for (int c=0; c<n; c++){
                if (grid[r][c] == 1) continue;
                set<int> s;
                for (int i=0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n){
                        if (grid[nr][nc] == 1){
                            s.insert(ds.findparent(nr*n + nc));
                        }
                    }
                }

                int sizetotal = 0;
                for (auto it : s){
                    sizetotal += ds.size[it];
                }
                mx = max(mx, sizetotal + 1);
            }
        }

        for (int i=0; i<n*n; i++){
            mx = max(mx, ds.size[ds.findparent(i)]);
        }
        return mx;
    }
};