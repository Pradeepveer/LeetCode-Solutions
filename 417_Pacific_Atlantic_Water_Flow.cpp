#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfspacific(vector<vector<int>>& pacific, vector<vector<int>>& heights, vector<int>& drow, vector<int>& dcol, int r, int c, int n, int m){
        if (pacific[r][c] == 1) return;
        pacific[r][c] = 1;
        
        for (int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && heights[nr][nc] >= heights[r][c]){
                dfspacific(pacific, heights, drow, dcol, nr, nc, n, m);
            }
        }
        return;
    }

    void dfsatlantic(vector<vector<int>>& atlantic, vector<vector<int>>& heights, vector<int>& drow, vector<int>& dcol, int r, int c, int n, int m){
        if (atlantic[r][c] == 1) return;
        atlantic[r][c] = 1;
        
        for (int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && heights[nr][nc] >= heights[r][c]){
                dfsatlantic(atlantic, heights, drow, dcol, nr, nc, n, m);
            }
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> ans;
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        
        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        for (int i=0; i<n; i++){
            dfspacific(pacific, heights, drow, dcol, i, 0, n, m);
        }

        for (int j=0; j<m; j++){
            dfspacific(pacific, heights, drow, dcol, 0, j, n, m);
        }

        for (int i=0; i<n; i++){
            dfsatlantic(atlantic, heights, drow, dcol, i, m-1, n, m);
        }

        for (int j=0; j<m; j++){
            dfsatlantic(atlantic, heights, drow, dcol, n-1, j, n, m);
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};  