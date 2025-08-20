#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<int> drow = {1, 0, -1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    vector<vector<int>> visited(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q; // {{row, col}, steps} 

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (mat[i][j] == 0) {
                visited[i][j] = 1;
                q.push({{i, j}, 0});
            }
            else visited[i][j] = 0;
        }
    }

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int steps = q.front(). second;
        q.pop();
        ans[r][c] = steps;

        for (int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >=0 && nr < n && nc >=0 && nc < m && !visited[nr][nc]){
                q.push({{nr,nc}, steps+1});
                visited[nr][nc] = 1;
            } 
        }
    }

    return ans;
}