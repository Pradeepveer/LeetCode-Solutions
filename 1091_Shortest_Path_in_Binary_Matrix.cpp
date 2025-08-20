#include<bits/stdc++.h>
using namespace std;


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 1 && grid[0][0] == 0) return 1;
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    vector<int> drow = {1, -1, 0, 0, 1, 1, -1, -1};
    vector<int> dcol = {0, 0, 1, -1, 1, -1, 1, -1};    
    queue<pair<int, pair<int, int>>> q; // {dist, {row, col}}
    
    dist[0][0] = 0;
    q.push({1, {0, 0}});

    while(!q.empty()){
        int d = q.front().first;
        int r = q.front().second.first;
        int c = q.front(). second.second;
        q.pop();

        for (int i=0; i<8; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist[nr][nc] > d + 1){
                dist[nr][nc] = d + 1;
                q.push({d+1, {nr, nc}});
                if (nr == n-1 && nc == n-1) return d+1;
            }
        }
    }

    return -1;
}