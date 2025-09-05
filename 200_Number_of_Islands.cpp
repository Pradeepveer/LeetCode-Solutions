#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == '1' && vis[i][j] == 0){
                    cnt++;

                    vis[i][j] = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for (int k=0; k<4; k++){
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if (nr < n && nr >= 0 && nc < m && nc >= 0 &&
                                grid[nr][nc] == '1' && vis[nr][nc] == 0){
                                q.push({nr, nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                }
            }
        }        
        return cnt;
    }
};