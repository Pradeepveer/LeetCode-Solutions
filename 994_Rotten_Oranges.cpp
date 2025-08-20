#include<bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m,0));
    int cntfresh = 0;
    
    
    int tmax = 0;
    queue<pair<pair<int,int>, int>> q;

    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == 2){
                vis[i][j] = 2;
                q.push({{i, j}, 0});
            }
            else vis[i][j] = 0;

            if (grid[i][j] == 1) cntfresh++;
        }
    }

    int drow[4] = {-1, 0, +1, 0};
    int dcol[4] = {0, -1, 0, +1};

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tmax = max(tmax, t);
        q.pop();

        for (int i=0; i<4; i++){
            int newr = r + drow[i];
            int newc = c + dcol[i];
            if (newr >=0 && newr < n && newc >= 0 && newc < m &&
                vis[newr][newc] == 0 && grid[newr][newc] == 1){
                    vis[newr][newc] = 2;
                    cntfresh--;
                    q.push({{newr,newc}, t+1});
                }
        }
    }

    if (cntfresh != 0) return -1;
    return tmax;
}