#include<bits/stdc++.h>
using namespace std;


int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<int> drow = {1, -1, 0, 0};
    vector<int> dcol = {0, 0, 1, -1};
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    // putting boundary 1's in queue
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i==0 || i==n-1 || j==0 || j==m-1){
                if (grid[i][j] == 1 && !visited[i][j]){
                    visited[i][j] = 1;
                    q.push({i, j});
                } 
            }
        }
    }

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1){
                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    int cnt = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == 1 && !visited[i][j]){
                cnt++;
            }
        }
    }

    return cnt;
}