#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& ans, int sr, int sc, int color, int initialcolor, vector<int>& drow, vector<int>& dcol){
    ans[sr][sc] = color;
    int n = ans.size();
    int m = ans[0].size();

    for (int i=0; i<4; i++){
        int nr = sr + drow[i];
        int nc = sc + dcol[i];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == initialcolor && ans[nr][nc] != color){
            dfs(ans, nr, nc, color, initialcolor, drow, dcol);
        }
    }
    return;
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialcolor = image[sr][sc];
    vector<vector<int>> ans = image;
    vector<int> drow = {1, 0, -1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    
    dfs(ans, sr, sc, color, initialcolor, drow, dcol);
    return ans;    
}