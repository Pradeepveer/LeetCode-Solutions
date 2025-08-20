#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int sr, int sc, vector<int> drow, vector<int> dcol){
    visited[sr][sc] = 1;
    int n = board.size();
    int m = board[0].size();

    for (int i=0; i<4; i++){
        int nr = sr + drow[i];
        int nc = sc + dcol[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && board[nr][nc] == 'O'){
            dfs(board, visited, nr, nc, drow, dcol);
        }
    }
    return;
}


void solve(vector<vector<char>>& board){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> drow = {0, 0, 1, -1};
    vector<int> dcol = {1, -1, 0, 0};

    for (int i=0; i<m; i++){
        // top
        if (board[0][i] == 'O' && !visited[0][i]){
            dfs(board, visited, 0, i, drow, dcol);
        }

        // bottom
        if (board[n-1][i] == 'O' && !visited[n-1][i]){
            dfs(board, visited, n-1, i, drow, dcol);
        }
    }

    for (int i=0; i<n; i++){
        // left
        if (board[i][0] == 'O' && !visited[i][0]){
            dfs(board, visited, i, 0, drow, dcol);
        }

        // bottom
        if (board[i][m-1] == 'O' && !visited[i][m-1]){
            dfs(board, visited, i, m-1, drow, dcol);
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!visited[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }
    return;
}
